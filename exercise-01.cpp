/*
Nama	: Bandana Irmal Abdillah
NPM		: 140810180025
Tanggal	: 14 Mei 2019
Deskripsi: exercise-01 strukdat-10
*/

#include <iostream>
using namespace std;

const int maxelemen = 255;
struct Queue{
	char isi[maxelemen];
	int head;
	int tail;
};

Queue q;

void createQueue(Queue& Q){
	Q.head = 0;
	Q.tail = -1;
}

void enqueue(Queue& Q, char elemen, int banyakantrian){
	
	if(Q.head == banyakantrian-1){
		cout <<"Antrian sudah penuh"<< endl;
	}
	else{
		Q.tail = Q.tail + 1;
		Q.isi[Q.tail] = elemen;
	}
}

void dequeue(Queue& Q, char& elemenHapus){
	
	if(Q.head>Q.tail){
		cout <<"Antrian kosong"<< endl;
	}
	else{
		elemenHapus = Q.isi[Q.head];
		for (int i=0; i<Q.tail; i++){
			Q.isi[i] = Q.isi[i+1];
		}
		Q.tail = Q.tail-1;
	}
}

main(){
	int antrian;
	char elemen, hapus;
	
	cout <<"Jumlah antrian : "; cin >> antrian;
	createQueue(q);
	cout <<"Insert Queue"<< endl;
	for(int i=0; i<antrian; i++){
		cout <<"Antrian ke-"<< i+1 <<" : "; cin >> elemen; 
		enqueue(q, elemen, antrian);
	}
	cout << endl;
	
	cout <<"List Antrian : ";
	for(int i = q.head; i <= q.tail; i++){
		cout << q.isi[i] << ", ";
	}

	cout << endl << endl;
	
	cout <<"Delete Queue" << endl;
	dequeue(q, hapus);

	cout <<"List Antrian : ";
	for(int i = q.head; i <= q.tail; i++){
		cout << q.isi[i] << ", ";
	}

}
