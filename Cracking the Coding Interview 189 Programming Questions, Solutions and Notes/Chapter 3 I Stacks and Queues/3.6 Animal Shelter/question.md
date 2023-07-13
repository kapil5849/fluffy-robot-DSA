> Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked list data structure.


The question asks us to design a system for an animal shelter that operates on a "first in, first out" basis. The shelter holds dogs and cats, and people can adopt either the oldest animal overall or choose a specific type (dog or cat) and receive the oldest animal of that type. We need to create data structures and implement operations such as enqueue (to add animals to the shelter), dequeueAny (to adopt the oldest animal), dequeueDog (to adopt the oldest dog), and dequeueCat (to adopt the oldest cat). We can use the built-in linked list data structure to implement this system.

# To solve this problem, we can use the following approach:

1. Create a class called `Animal` with attributes such as `name`, `type` (dog or cat), and `arrivalTime`.
2. Create separate queues for dogs and cats to maintain the arrival order of each animal type.
3. Implement the `enqueue` operation to add an animal to the appropriate queue. The `enqueue` operation will take the animal's name, type, and arrival time as parameters.
4. Implement the `dequeueAny` operation to adopt the oldest animal overall. Compare the arrival times of the animals at the front of both queues and dequeue the one with the earlier arrival time.
5. Implement the `dequeueDog` operation to adopt the oldest dog. Dequeue the animal from the dog queue.
6. Implement the `dequeueCat` operation to adopt the oldest cat. Dequeue the animal from the cat queue.


## Explanation:
1. We define a class called `Animal` to represent an animal in the shelter. It has attributes such as `name`, `type` (dog or cat), and `arrivalTime`.
2. We create a class called `AnimalShelter` to manage the animal shelter system. It has two queues: `dogQueue` and `catQueue` to hold dogs and cats, respectively. We also have a `timestamp` variable to track the arrival time of animals.
3. The `enqueue` operation takes the animal's name and type as parameters. It creates an `Animal` object with the given details and adds it to the appropriate queue based on the animal's type.
4. The `dequeueAny` operation dequeues the oldest animal overall. If one of the queues is empty, it dequeues the animal from the non-empty queue. Otherwise, it compares the arrival times of the animals at the front of both queues and dequeues the one with the earlier arrival time.
5. The `dequeueDog` operation dequeues the oldest dog from the `dogQueue`.
6. The `dequeueCat` operation dequeues the oldest cat from the `catQueue`.
7. In the `main` function, we create an instance of `AnimalShelter` called `shelter`.
8. We enqueue four animals: two dogs and two cats.
9. We dequeue the oldest animal overall using the `dequeueAny` operation and print its details if available.
10. We dequeue the oldest dog using the `dequeueDog` operation and print its name if available.
11. We dequeue the oldest cat using the `dequeueCat` operation and print its name if available.

### This implementation demonstrates how to create a data structure to manage an animal shelter system where animals can be enqueued and dequeued based on their arrival time or specific type.
---