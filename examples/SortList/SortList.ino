#include "SortList.h"

struct Person {
  int id;
  String name;
  Person(int id, String name): id(id), name(name) {}
};

template<typename T>
void printArray(T array[], uint8_t size) {
  for (int i = 0; i < size; i++) {
    Serial.print(array[i]);
    Serial.print("  ");
  }
  Serial.println();
}

template<>
void printArray(Person array[], uint8_t size) {
  for (int i = 0; i < size; i++) {
    Serial.print(array[i].id);
    Serial.print("  ");
    Serial.print(array[i].name);
    Serial.println();
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);

  /* Regular variable example */

  //Create array of arbitrary number with arbitrary order
  double numbers[10] = {2.12, 7.43, 5.85, 6.13, 12.56, 74.76, 9.542, 345.1, 1.23456, 7.2341};

  //Print the array to serial monitor
  Serial.println("Unsorted array of double: ");
  printArray(numbers, 10);

  //Sort the array using bult-in sorting algorithm
  SortList<double>::sort(numbers, 10);

  //Print the array to serial monitor after being sorted
  Serial.println("\nSorted array of double: ");
  printArray(numbers, 10);

  //Reverse the order of elements in array
  SortList<double>::reverse(numbers, 10);

  //Print the array to serial monitor after being reversed
  Serial.println("\nReversed array of double: ");
  printArray(numbers, 10);


  /* Custom object example */

  //Create array of Person object
  Person people[5] = {
    Person(3, "Clark"),
    Person(1, "Zacharia"),
    Person(5, "Anabil"),
    Person(4, "Hummingbird"),
    Person(2, "Melissa")
  };

  //Print the array to serial monitor
  Serial.println("\n\nUnsorted array of Person object: ");
  printArray(people, 5);

  //Sort the array by name
  SortList<Person>::sort(people, 5, [](Person a, Person b) -> bool { return a.name.compareTo(b.name) > 0; });

  //Print the array to serial monitor after being sorted by name
  Serial.println("\nSorted by name: ");
  printArray(people, 5);

  //Sort the array by id
  SortList<Person>::sort(people, 5, [](Person a, Person b) -> bool { return a.id > b.id; });

  //Print the array to serial monitor after being sorted by id
  Serial.println("\nSorted by id: ");
  printArray(people, 5);

  //Reverse the order of elements in array
  SortList<Person>::reverse(people, 5);

  //Print the array to serial monitor after being reversed
  Serial.println("\nReversed array of Person object: ");
  printArray(people, 5);

}

void loop() {}
