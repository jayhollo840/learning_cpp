```c++
#include <iostream>

int main(void) {
	// Print data types and their sizes
	std::cout << "Primative data types and sizes in bytes:" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "wchar_t: " << sizeof(wchar_t) << std::endl;
	std::cout << "short int" << sizeof(short int) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "long int: " << sizeof(long int) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "long double: " << sizeof(long double) << std::endl;
	
	return 0;
}
```

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the hash table entry.
typedef struct CounterEntry {
    int taskNumber;
    int count;
    struct CounterEntry *next;
} CounterEntry;

// Define the struct for the hash table.
#define HASH_TABLE_SIZE 100
typedef struct HashTable {
    CounterEntry *entries[HASH_TABLE_SIZE];
} HashTable;

// Function to create a new hash table.
HashTable* createHashTable() {
    HashTable *table = malloc(sizeof(HashTable));
    memset(table->entries, 0, sizeof(table->entries));
    return table;
}

// Hash function to convert a task number to an index.
unsigned int hash(int taskNumber) {
    return taskNumber % HASH_TABLE_SIZE;
}

// Function to create a new counter entry.
CounterEntry* createCounterEntry(int taskNumber) {
    CounterEntry *entry = malloc(sizeof(CounterEntry));
    entry->taskNumber = taskNumber;
    entry->count = 0;
    entry->next = NULL;
    return entry;
}

// Function to increment the counter for a task.
void incrementTaskCounter(HashTable *table, int taskNumber) {
    unsigned int index = hash(taskNumber);
    CounterEntry *entry = table->entries[index];

    // Search for an existing entry for the task.
    while (entry != NULL) {
        if (entry->taskNumber == taskNumber) {
            entry->count += 1;
            return;
        }
        entry = entry->next;
    }

    // No existing entry found, create a new one.
    entry = createCounterEntry(taskNumber);
    entry->count = 1;
    // Insert it at the beginning of the linked list.
    entry->next = table->entries[index];
    table->entries[index] = entry;
}

// Function to get the counter for a task.
int getTaskCounter(HashTable *table, int taskNumber) {
    unsigned int index = hash(taskNumber);
    CounterEntry *entry = table->entries[index];

    while (entry != NULL) {
        if (entry->taskNumber == taskNumber) {
            return entry->count;
        }
        entry = entry->next;
    }

    // If the task does not exist in the table, return 0.
    return 0;
}

// Remember to free the hash table and all its entries when done.
// ... (Functions to delete entries and free table)

int main() {
    HashTable *table = createHashTable();
    
    // Example usage.
    incrementTaskCounter(table, 42);
    incrementTaskCounter(table, 42);
    incrementTaskCounter(table, 99);
    
    printf("Task 42 count: %d\n", getTaskCounter(table, 42));
    printf("Task 99 count: %d\n", getTaskCounter(table, 99));

    // Free the table after use.
    // ... (Code to free the table)
    
    return 0;
}

// Function to reset the counter for a task.
void resetTaskCounter(HashTable *table, int taskNumber) {
    unsigned int index = hash(taskNumber);
    CounterEntry *entry = table->entries[index];

    // Search for the entry for the task.
    while (entry != NULL) {
        if (entry->taskNumber == taskNumber) {
            entry->count = 0; // Reset the count to 0.
            return;
        }
        entry = entry->next;
    }

    // If the entry doesn't exist, no need to reset.
}