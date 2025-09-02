#include <iostream>

// Funzione che conta quanti elementi in un array sono maggiori di k
int greaterThan(const int A[], int size, int k) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (A[i] > k) {
            count++;
        }
    }
    return count;
}

// Funzione che verifica se un elemento k è presente in un array
bool member(const int A[], int size, int k) {
    for (int i = 0; i < size; ++i) {
        if (A[i] == k) {
            return true;
        }
    }
    return false;
}

// Funzione che trova il valore e la posizione del più grande elemento in un array
int largest(const int A[], int size, int &position) {
    if (size <= 0) {
        // Gestionare l'array vuoto
        return 0;
    }

    int maxVal = A[0];
    position = 0;

    for (int i = 1; i < size; ++i) {
        if (A[i] > maxVal) {
            maxVal = A[i];
            position = i;
        }
    }

    return maxVal;
}

// Funzione che rimuove la prima occorrenza di k in un array
void removeElement(int A[], int size, int k) {
    int i = 0;
    while (i < size && A[i] != k) {
        ++i;
    }

    if (i < size) {
        for (int j = i; j < size - 1; ++j) {
            A[j] = A[j + 1];
        }
        A[size - 1] = 0;
    }
}

// Funzione che verifica se gli elementi in un array sono in ordine crescente, descrescente o costante
enum Order { INCREASING, DECREASING, CONSTANT, UNORDERED };

Order ordering(const int A[], int size) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < size; ++i) {
        if (A[i] > A[i - 1]) {
            decreasing = false;
        } else if (A[i] < A[i - 1]) {
            increasing = false;
        }
    }

    if (increasing) {
        return INCREASING;
    } else if (decreasing) {
        return DECREASING;
    } else {
        return UNORDERED;
    }
}

// Funzione che inverte gli elementi in un array
void reverse(int A[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        std::swap(A[i], A[size - i - 1]);
    }
}

// Funzione ricorsiva che cerca un elemento k in un array ordinato
bool find(const int A[], int low, int high, int k) {
    if (low > high) {
        return false;
    }

    int mid = low + (high - low) / 2;

    if (A[mid] == k) {
        return true;
    } else if (A[mid] < k) {
        return find(A, mid + 1, high, k);
    } else {
        return find(A, low, mid - 1, k);
    }
}

// Struttura per la catena circolare
struct Node {
    int value;
    Node* next;
};

// Funzione che crea una catena circolare di k celle e restituisce il puntatore alla prima cella
Node* chain(int k) {
    if (k <= 0) {
        return nullptr;
    }

    Node* head = new Node{1, nullptr};
    Node* current = head;

    for (int i = 2; i <= k; ++i) {
        current->next = new Node{i, nullptr};
        current = current->next;
    }

    current->next = head; // Collega l'ultimo elemento al primo per formare una catena circolare

    return head;
}

// Funzione che dealloca tutte le celle della catena circolare
void clear(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}

int main() {
    // Esempio di utilizzo delle funzioni
    const int arraySize = 5;
    int array[arraySize] = {3, 1, 4, 1, 5};

    std::cout << "Number of elements greater than 2: " << greaterThan(array, arraySize, 2) << std::endl;
    std::cout << "Is 4 a member of the array? " << std::boolalpha << member(array, arraySize, 4) << std::endl;

    int position;
    std::cout << "Largest element in the array: " << largest(array, arraySize, position) << " at position " << position << std::endl;

    removeElement(array, arraySize, 1);
    std::cout << "Array after removing the first occurrence of 1: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    Order order = ordering(array, arraySize);
    std::cout << "Order of elements in the array: ";
    switch (order) {
        case INCREASING:
            std::cout << "Increasing";
            break;
        case DECREASING:
            std::cout << "Decreasing";
            break;
        case CONSTANT:
            std::cout << "Constant";
            break;
        case UNORDERED:
            std::cout << "Unordered";
            break;
    }
    std::cout << std::endl;

    reverse(array, arraySize);
    std::cout << "Array after reversing: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    const int sortedArraySize = 8;
    int sortedArray[sortedArraySize] = {1, 2, 3, 4, 5, 6, 7, 8};
    int searchValue = 5;
    std::cout << "Is " << searchValue << " in the sorted array? " << std::boolalpha << find(sortedArray, 0, sortedArraySize - 1, searchValue) << std::endl;

    int k = 3;
    Node* circularChain = chain(k);
    std::cout << "Circular chain created with " << k << " cells." << std::endl;

    // Esempio di deallocazione della catena circolare
    clear(circularChain);
    std::cout << "Circular chain deallocated." << std::endl;

    return 0;
}
