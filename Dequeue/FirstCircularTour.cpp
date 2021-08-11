#include <bits/stdc++.h>
using namespace std;

int getInitPoint(vector<int>& petrol, vector<int>& distance)
{
	/*
		Petrol:		[4	8	7	4]
		Distance:	[6	5	3	5]
		Travel:		[-2	3	4	-1]
	*/
	int initPump = 0;
	int currFuelLeft = 0, prevFuelLeft = 0;
	int numPetrolPumps = petrol.size();

	for(int i=0; i < numPetrolPumps; i++) {
		currFuelLeft += (petrol[i] - distance[i]);

		if(currFuelLeft < 0) {
			initPump = i+1;
			prevFuelLeft += currFuelLeft;
			currFuelLeft = 0;
		}
	}

	return ((currFuelLeft + prevFuelLeft) >= 0) ? (initPump+1) : -1;

}

std::ostream& operator<<(std::ostream& out, vector<int> arr) {
	for(int i=0; i<arr.size(); i++)
		out << arr[i] << " ";
	out << std::endl;

	return out;
}

int main() {
	vector<int> petrol, dist;
	int initPump;

	petrol = {4, 8, 7, 4};
	dist = {6, 5, 3, 5};
	cout << "\nPetrol at pumps: " << petrol;
	cout << "Distance between pumps: " << dist;
	initPump = getInitPoint(petrol, dist);
	cout << "Initial pump to visit all pumps in circular manner: " << initPump << endl;

	petrol = {8, 9, 4};
	dist = {5, 10, 12};
	cout << "\nPetrol at pumps: " << petrol;
	cout << "Distance between pumps: " << dist;
	initPump = getInitPoint(petrol, dist);
	cout << "Initial pump to visit all pumps in circular manner: " << initPump << endl;

	petrol = {4, 8};
	dist = {5, 6};
	cout << "\nPetrol at pumps: " << petrol;
	cout << "Distance between pumps: " << dist;
	initPump = getInitPoint(petrol, dist);
	cout << "Initial pump to visit all pumps in circular manner: " << initPump << endl;

	petrol = {50, 10, 60, 100};
	dist = {30, 20, 100, 10};
	cout << "\nPetrol at pumps: " << petrol;
	cout << "Distance between pumps: " << dist;
	initPump = getInitPoint(petrol, dist);
	cout << "Initial pump to visit all pumps in circular manner: " << initPump << endl;

	return 0;
}