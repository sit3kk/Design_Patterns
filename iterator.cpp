#include <iostream>
#include <vector>

template <typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual ~Iterator() {}
};

template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T>& data;
    int index;
public:
    ConcreteIterator(std::vector<T>& data) : data(data), index(0) {}

    bool hasNext() override {
        return index < data.size();
    }

    T next() override {
        return data[index++];
    }
};

template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
    virtual ~Aggregate() {}
};

template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> data;
public:
    ConcreteAggregate(std::initializer_list<T> data) : data(data) {}

    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(data);
    }

    void add(T value) {
        data.push_back(value);
    }
};

// Klient
int main() {
    ConcreteAggregate<int> collection({1, 2, 3, 4, 5});
    Iterator<int>* iterator = collection.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    delete iterator;
    return 0;
}
