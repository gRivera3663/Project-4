#pragma once
#include <vector>
#include <string>
#include <map>

typedef int Vertex;
using namespace std;

class Graph {
public:
	Graph(int n); // TO DO
	int size(); // TO DO
	void addLabel(Vertex i, string s); // TO DO
	void addEdge(Vertex i, Vertex j); // TO DO
	vector<Vertex> getAdjacentVertices(Vertex); // TO DO

	Vertex getVertex(string label) // OPTIONAL: may help your code
    {
        return labelsToInt[label];
    }
	string getLabel(Vertex n) // OPTIONAL: may help your code
    {
        return intToLabels[n];
    }

private:
	// TO DO
	// member variables and functions to implement the public member functions
	map<string,Vertex> labelsToInt; // label = int
	map<Vertex,string> intToLabels; // int = label
    vector<Vertex> listOfVert;
    map<Vertex, vector<Vertex>> adj;
    int Size;
};



// TO DO
// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string& person);

// COMPLETED
// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string& filename);

// COMPLETED
// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string& filename);
