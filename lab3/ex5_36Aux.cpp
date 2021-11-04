class ex5_36Aux{
	private:
		int r;
	public:
		rectangle ** getRoomArray(){
			cout << "Enter number of rooms: " << endl;
			cin >> r;
			rectangle roomarr = new rectangle[r + 1];
			roomarr[r + 1] = nullptr;
			return roomarr;
		}

		void getRoomData(rectangle ** rooms){
			for(int i = 0; i < r; i++){
				cout << rooms[i].getLength() * rooms[i].getWidth() << endl;
			}
		}
		double getTotalArea(rectangle ** rooms){
			double total = 0;
			for(int j = 0; j < r; j++){
				total += rooms[j].getLength() * rooms[j].getWidth();
			}
			return total;
		}
		rectangle largestPerimeter(rectangle ** rooms){
			double largest;
			int base = 0;
			double temp;
			for(int k = 0; k < r; k++){
				temp = rooms[k].getLength() * rooms[k].getWidth();
				if (temp > base){
					largest = temp;
				}
			}
			return rooms[largest - 1];
		}
		void reportOnLargest(rectangle & largeRoom){
			cout << "Length: " << largeRoom.getLength() << endl;
			cout << "Width: " << largeRoom.getWidth() << endl;
			cout << "Perimeter: " << (2 * largeRoom.getLength) + (2 * largeRoom.getWidth);
		}
		void reportOnTotalArea(rectangle ** rooms){
			double totalarea;
			for(int l = 0; l < r; l++){
				totalarea += rooms.getTotalArea();
			}
			cout << "Total area is: " << totalarea << endl;
		}
};
