#include <fstream>
#include <iostream>
#include <sstream>  // for std::istringstream
#include "Graph.h"

// TO DO
// initialize an undirected graph that can store at most n vertices
Graph::Graph(int n) {
    Adj.resize(n);
}

// TO DO
// return the maximum number of vertices
int Graph::size() {
    return Adj.size();
}

// TO DO
// give a string label to vertex
void Graph::addLabel(Vertex i, string s) {
    intToLabels[i] = s;
    labelsToInt[s] = i;
    
    AdjList temp = {i};
    Adj.push_back(temp);
}

// TO DO
// add an edge between vertices i and j
void Graph::addEdge(Vertex i, Vertex j) {
    for (vector<AdjList>::iterator x = Adj.begin(); x != Adj.end(); x++)
    {
        if ((*x).vert == i)
        {
            (*x).adj.push_back(j);
        }
        else if((*x).vert == j)
        {
            (*x).adj.push_back(i);
        }
    }
}

// TO DO
// return a vector of vertices adjacent to vertex n
vector<Vertex> Graph::getAdjacentVertices(Vertex n) {
    vector<Vertex> output;
    for (vector<AdjList>::iterator x = Adj.begin(); x != Adj.end(); x++)
    {
        if ((*x).vert == n)
        {
            output = (*x).adj;
        }
    }
    return output;
}


// TO DO
// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string &person) {
    vector<string> output;
    Vertex id = graph.getVertex(person);
    
    vector<Vertex> friends = graph.getAdjacentVertices(id);
    vector<Vertex> friendsOfFriends;
    
    for (vector<Vertex>::iterator x = friends.begin(); x != friends.end(); x++)
    {
        vector<Vertex> temp = graph.getAdjacentVertices(*x);
        for (vector<Vertex>::iterator y = temp.begin(); y != temp.end(); y++)
        {
            friendsOfFriends.push_back(*y);
        }
    }
    
    sort(friendsOfFriends.begin(), friendsOfFriends.end());
    friendsOfFriends.erase(unique(friendsOfFriends.begin(), friendsOfFriends.end()), friendsOfFriends.end());
    friendsOfFriends.erase(remove(friendsOfFriends.begin(), friendsOfFriends.end(), id), friendsOfFriends.end());
    
    for (vector<Vertex>::iterator x = friendsOfFriends.begin(); x != friendsOfFriends.end(); x++)
    {
        output.push_back(graph.getLabel(*x));
    }

    return output;
}


// COMPLETED
// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string& filename) {
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile)
		throw invalid_argument("Unable to open file " + filename);
	string s;
	int i;
	while (!inputFile.eof()) {
		inputFile >> i >> s;
		// cout << "adding label " << i << ": " << s << endl;
		graph.addLabel(i, s);
	}
}

// COMPLETED
// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string& filename) {
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile)
		throw invalid_argument("Unable to open file " + filename);

	for (string line; getline(inputFile, line); ) {
		istringstream iss(line);
		int i;
		iss >> i;
		int j;
		while (!iss.eof()) {
			iss >> j;
			// cout << "adding edge " << i << " to " << j << endl;
			graph.addEdge(i, j);
		}
	}
}
