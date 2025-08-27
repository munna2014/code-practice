#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Customer
{
    int arrival, departure, index;
};

int main()
{
    int n;
    cin >> n;

    vector<Customer> customers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end(), [](const Customer &a, const Customer &b)
         { return a.arrival < b.arrival; });

    // Priority queue to store (departure_time, room_number) of occupied rooms
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> room_assignment(n);
    int next_room = 1;

    for (int i = 0; i < n; i++)
    {
        int arrival = customers[i].arrival;
        int departure = customers[i].departure;
        int original_index = customers[i].index;

        // Check if any room is available (departure time < arrival time)
        if (!pq.empty() && pq.top().first < arrival)
        {
            // Reuse an available room
            int room_num = pq.top().second;
            pq.pop();
            room_assignment[original_index] = room_num;
            pq.push({departure, room_num});
        }
        else
        {
            // Need a new room
            room_assignment[original_index] = next_room;
            pq.push({departure, next_room});
            next_room++;
        }
    }

    cout << next_room - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << room_assignment[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}