#ifndef SORTLIST_H
#define SORTLIST_H

template<typename T>
class SortList {
  public:
    static void sort(T array[], size_t size) {
      insertionSort(array, size, SortList::builtinPredicate);
    }

    static void sort(T array[], size_t size, bool(*predicate)(T, T)) {
      insertionSort(array, size, predicate);
    }

    static void reverse(T array[], size_t size) {
      for (size_t i = 0; i < size / 2; i++) {
        T buffer = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = buffer;
      }
    }


  private:
    static bool builtinPredicate(T first, T second) {
      return first > second;
    }

    static void insertionSort(T array[], size_t size, bool(*predicate)(T, T)) {
      for (size_t i = 1; i < size; i++) {
        for (size_t j = i; j > 0 && predicate(array[j - 1], array[j]); j--) {
          T tmp = array[j - 1];
          array[j - 1] = array[j];
          array[j] = tmp;
        }
      }
    }
};

#endif
