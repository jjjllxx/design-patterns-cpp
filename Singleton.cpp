class BillPughSingleton {
private:
  BillPughSingleton() = default;

public:
  static BillPughSingleton *getInstance() {
    static BillPughSingleton instance;
    return &instance;
  }
};

template <typename T> class Singleton {
public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static T &getInstance() {
    static T instance;
    return instance;
  }

protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};

class Logger : public Singleton<Logger> {
  friend class Singleton<Logger>;

private:
  Logger() = default;
};

class LazySingleton {
private:
  static LazySingleton *instance;

  LazySingleton() = default;

public:
  static LazySingleton *getInstance() {
    if (instance == nullptr) {
      instance = new LazySingleton();
    }
    return instance;
  }
};

class EagerSingleton {
private:
  static EagerSingleton *instance;

  EagerSingleton() = default;

public:
  static EagerSingleton *getInstance() { return instance; }
};
