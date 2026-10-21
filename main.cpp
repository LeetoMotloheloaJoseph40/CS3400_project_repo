/*#include <iostream>


int main() {
	
	
	return 0;
}
*/
#include <iostream>
#include "Vehiclelist.h"
#include "Sorting.h"
using namespace std;

void showArray(Vehicle a[], int n) {
    for (int i = 0; i < n; i++) a[i].display();
}

int main() {
    Vehiclelist vehicles;

    // 1. Insert
    cout << "--- Insert ---\n";
    vehicles.insertEnd(Vehicle("BUS01", "A123", "Transport", "Bus", "Route 1", 40, "Available"));
    vehicles.insertEnd(Vehicle("AMB01", "B456", "Special", "Ambulance", "None", 4, "Available"));
    vehicles.insertFront(Vehicle("CAR01", "C789", "Private", "Car", "None", 5, "In Service"));
    vehicles.insertEnd(Vehicle("BUS02", "D012", "Transport", "Bus", "Route 2", 60, "Maintenance"));
    vehicles.display();
    cout << "Size: " << vehicles.getsize() << endl;

    // 2. Duplicate ID (should be rejected)
    cout << "\n--- Duplicate test ---\n";
    if (!vehicles.insertEnd(Vehicle("BUS01", "X999", "Transport", "Bus", "Route 9", 10, "Available")))
        cout << "Duplicate rejected (correct)\n";

    // 3. Linear search
    cout << "\n--- Linear search ---\n";
    Node* found = vehicles.search("AMB01");
    if (found != NULL) found->data.display();
    else cout << "Not found\n";

    if (vehicles.search("ZZZ99") == NULL)
        cout << "ZZZ99 not found (correct)\n";

    // 4. Update (search, then use setters)
    cout << "\n--- Update ---\n";
    found = vehicles.search("BUS02");
    if (found != NULL) {
        found->data.setstatus("Available");
        found->data.display();
    }

    // 5. Remove
    cout << "\n--- Remove ---\n";
    if (vehicles.remove("CAR01")) cout << "CAR01 removed\n";
    if (!vehicles.remove("CAR01")) cout << "CAR01 already gone (correct)\n";
    vehicles.display();
    cout << "Size: " << vehicles.getsize() << endl;

    // 6. Sorting (copy list to array first)
    int n = vehicles.getsize();
    Vehicle* arr = vehicles.toArray();

    cout << "\n--- Insertion sort by capacity ---\n";
    insertionSort(arr, n, 2);
    showArray(arr, n);

    cout << "\n--- Merge sort by plate ---\n";
    mergeSort(arr, n, 4);
    showArray(arr, n);

    // 7. Binary search (array must be sorted by ID)
    cout << "\n--- Binary search ---\n";
    mergeSort(arr, n, 1);
    int pos = binarysearch(arr, n, "BUS01");
    if (pos != -1) arr[pos].display();
    else cout << "Not found\n";

    if (binarysearch(arr, n, "ZZZ99") == -1)
        cout << "ZZZ99 not found (correct)\n";

    delete[] arr;

    // 8. Save and load
    cout << "\n--- Save and load ---\n";
    vehicles.saveToFile("vehicles.txt");

    Vehiclelist loaded;
    loaded.loadFromFile("vehicles.txt");
    cout << "Loaded " << loaded.getsize() << " vehicles:\n";
    loaded.display();

    // 9. Empty list
    cout << "\n--- Empty list ---\n";
    Vehiclelist empty;
    empty.display();

    return 0;
}
