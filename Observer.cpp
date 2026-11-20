#include <memory>
#include <string>
#include <vector>

class IObserver {
public:
  virtual ~IObserver() = default;
  virtual void update(std::string msg) = 0;
};

class Folder {
  std::vector<std::weak_ptr<IObserver>> observers;

public:
  void attach(std::shared_ptr<IObserver> &ob) { observers.emplace_back(ob); }

  void deattach(std::shared_ptr<IObserver> &ob) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
      if (ob == it->lock()) {
        observers.erase(it);
        break;
      }
    }
  }

  void notify(const std::string &msg) {
    std::erase_if(observers, [](auto &o) { return o.expired(); });

    for (const auto &ob : observers) {
      ob.lock()->update(msg);
    }
  }
};
