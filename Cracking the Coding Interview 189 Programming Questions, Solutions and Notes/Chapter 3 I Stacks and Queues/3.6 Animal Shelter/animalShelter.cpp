
#include <iostream>
#include <queue>
#include <string>

class Animal {
public:
    std::string name;
    std::string type;
    int arrivalTime;

    Animal(std::string animalName, std::string animalType, int time) {
        name = animalName;
        type = animalType;
        arrivalTime = time;
    }
};

class AnimalShelter {
private:
    std::queue<Animal*> dogQueue;
    std::queue<Animal*> catQueue;
    int timestamp;

public:
    AnimalShelter() {
        timestamp = 0;
    }

    void enqueue(std::string name, std::string type) {
        Animal* animal = new Animal(name, type, timestamp++);
        if (type == "dog") {
            dogQueue.push(animal);
        } else if (type == "cat") {
            catQueue.push(animal);
        }
    }

    Animal* dequeueAny() {
        if (dogQueue.empty() && catQueue.empty()) {
            std::cout << "No animals available for adoption." << std::endl;
            return nullptr;
        } else if (dogQueue.empty()) {
            return dequeueCat();
        } else if (catQueue.empty()) {
            return dequeueDog();
        } else {
            Animal* dog = dogQueue.front();
            Animal* cat = catQueue.front();
            if (dog->arrivalTime < cat->arrivalTime) {
                return dequeueDog();
            } else {
                return dequeueCat();
            }
        }
    }

    Animal* dequeueDog() {
        if (dogQueue.empty()) {
            std::cout << "No dogs available for adoption." << std::endl;
            return nullptr;
        }

        Animal* dog = dogQueue.front();
        dogQueue.pop();
        return dog;
    }

    Animal* dequeueCat() {
        if (catQueue.empty()) {
            std::cout << "No cats available for adoption." << std::endl;
            return nullptr;
        }

        Animal* cat = catQueue.front();
        catQueue.pop();
        return cat;
    }
};

int main() {
    AnimalShelter shelter;

    // Enqueue animals


    shelter.enqueue("Dog 1", "dog");
    shelter.enqueue("Cat 1", "cat");
    shelter.enqueue("Dog 2", "dog");
    shelter.enqueue("Cat 2", "cat");

    // Dequeue the oldest animal overall
    Animal* oldestAnimal = shelter.dequeueAny();
    if (oldestAnimal) {
        std::cout << "Adopted the oldest animal overall: " << oldestAnimal->name << " (Type: " << oldestAnimal->type << ")" << std::endl;
    }

    // Dequeue the oldest dog
    Animal* oldestDog = shelter.dequeueDog();
    if (oldestDog) {
        std::cout << "Adopted the oldest dog: " << oldestDog->name << std::endl;
    }

    // Dequeue the oldest cat
    Animal* oldestCat = shelter.dequeueCat();
    if (oldestCat) {
        std::cout << "Adopted the oldest cat: " << oldestCat->name << std::endl;
    }

    return 0;
}
