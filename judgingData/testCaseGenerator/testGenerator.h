#ifndef TESTGENRATOR_H
#define TESTGENRATOR_H
#include <bits/stdc++.h>
using namespace std;

/*
 * FolkaGenerator Class Documentation
 * -----------------------------------
 * A utility class for generating random test data for competitive programming.
 *
 * -------------------- Helper Struct --------------------
 * struct Random
 *   long long next(long long l, long long r)
 *     - Returns a random integer in the inclusive range [l, r].
 *
 * -------------------- Printing Functions --------------------
 * static void printVector(auto myVec)
 *   - Prints the elements of a vector separated by spaces.
 *
 * static void printGraph(auto myUGraph)
 *   - Prints a 2D vector representing graph edges row by row.
 *
 * static void shuffleVector(auto myVec)
 *   - Shuffles the elements of a vector randomly.
 *
 * static vector<long long> splitValue(long long valueToSplit, int numberOfSplits, bool hasZeroes)
 *   - Splits a value into 'numberOfSplits' random parts.
 *   - If hasZeroes = false, each part is at least 1.
 *   - Returns a shuffled vector of the parts.
 *
 * -------------------- Vector Generators --------------------
 * static vector<long long> generateVector(int sizeOfVector, long long elementLowerBound, long long elementUpperBound, bool printTheSample)
 *   - Generates a vector of random integers in [elementLowerBound, elementUpperBound].
 *   - Prints the vector if printTheSample = true.
 *
 * static vector<int> generatePermutationVector(int sizeOfVector, bool printTheSample)
 *   - Generates a random permutation of numbers from 1 to sizeOfVector.
 *   - Prints the permutation if printTheSample = true.
 *
 * -------------------- Tree Generators --------------------
 * static vector<vector<int>> generateUnweightedTree(int numberOfNodes, bool printTheSample)
 *   - Generates a random unweighted tree with 'numberOfNodes'.
 *   - Each edge is represented as [child, parent].
 *
 * static vector<vector<long long>> generateWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample)
 *   - Generates a random weighted tree.
 *   - Each edge is represented as [child, parent, weight].
 *
 * static vector<vector<long long>> generateLinerWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample)
 *   - Generates a linear weighted tree where node i connects to i-1.
 *   - Edge weights are in [weightLowerBound, weightUpperBound].
 *
 * static vector<vector<long long>> generateLinerUnweightedTree(int numberOfNodes, bool printTheSample)
 *   - Generates a linear unweighted tree where node i connects to i-1.
 *
 * -------------------- Unconnected Graph Generators --------------------
 * static vector<vector<int>> generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample)
 *   - Generates a random unconnected unweighted graph.
 *   - Number of edges is in [minNumberOfEdges, maxNumberOfEdges].
 *   - Can include cycles if includeCycle = true.
 *
 * static vector<vector<long long>> generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample)
 *   - Generates a random unconnected weighted graph.
 *   - Each edge is [node1, node2, weight].
 *
 * -------------------- Connected Graph Generators --------------------
 * static vector<vector<int>> generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample)
 *   - Generates a random connected unweighted graph.
 *   - Uses a tree plus extra edges to satisfy edge count.
 *
 * static vector<vector<long long>> generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample)
 *   - Generates a random connected weighted graph.
 *   - Each edge is [node1, node2, weight].
 *
 * -------------------- String Generators --------------------
 * static string generateString(int length, string all)
 *   - Generates a string of given length using characters from 'all'.
 *
 * static string generateString(int length, char l, char r)
 *   - Generates a string of given length using characters in the range [l, r].
 *
 * static string generateString(int length, vector<pair<char, char>> ranges)
 *   - Generates a string of given length using multiple character ranges.
 */

// Uncomment to use it locally
struct Random {
    long long next(long long l, long long r) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long long> distr(l , r);
        return distr(gen);
    }
};
Random rnd;

class FolkaGenerator {
private:

public:
    // Printing functions
    template< typename T >
    static void printVector(const vector< T > &myVec);

    template< typename T >
    static void printGraph(const vector< vector< T > > &);

    template< typename T >
    static void shuffleVector(vector< T > &myVec);

    static vector< long long > splitValue(long long valueToSplit, int numberOfSplits, bool hasZeroes);

    // Generating Vectors
    static vector< long long > generateVector(int sizeOfVector, long long elementLowerBound, long long elementUpperBound, bool printTheSample);
    static vector< int > generatePermutationVector(int sizeOfVector, bool printTheSample);

    // Generating Trees
    static vector< vector< int > > generateUnweightedTree(int numberOfNodes , bool printTheSample);
    static vector< vector< long long > > generateWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample);
    static vector< vector< long long > > generateLinerWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample);
    static vector< vector< long long > > generateLinerUnweightedTree(int numberOfNodes, bool printTheSample);
    // Generating Unconnected Graphs
    static vector< vector< int > > generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample);
    static vector< vector< long long > > generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample);

    // Generating Connected Graphs
    static vector< vector< int > > generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample);
    static vector< vector< long long > > generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample);

    // Generating Directed Graphs
    static vector< vector< int > > generateDirectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample);
    static vector< vector< long long > > generateDirectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample);

    // Generating Strings
    static string generateString(int length, string all);
    static string generateString(int length, char l, char r);
    static string generateString(int length, vector< pair< char , char > > ranges);
};

// Implementation
template< typename T >
void FolkaGenerator::printVector(const vector< T > &myVec) {
    for(int i = 0; i < (int)myVec.size(); i++) {
        cout << myVec[i];
        if(i + 1 < (int)myVec.size()) {
            cout << ' ';
        }
    }
}

template< typename T >
void FolkaGenerator::printGraph(const vector< vector< T > > &myUGraph) {
    for(int i = 0; i < (int)myUGraph.size(); i++) {
        for(int j = 0; j < (int)myUGraph[i].size(); j++) {
            cout << myUGraph[i][j];
            if(j + 1 < (int)myUGraph[i].size()) {
                cout << " ";
            }
        }
        if(i + 1 < (int)myUGraph.size()) {
            cout << endl;
        }
    }
}

template< typename T >
void FolkaGenerator::shuffleVector(vector< T > &myVec) {
    vector< int > p = generatePermutationVector((int)myVec.size(), false);
    vector< T > tmp = myVec;
    for(int i = 0; i < (int)p.size(); i++) {
        tmp[i] = myVec[p[i] - 1];
    }
    myVec = tmp;
}


vector< long long > FolkaGenerator::splitValue(long long valueToSplit, int numberOfSplits, bool hasZeroes) {
    vector< long long > result;
    for (int step = 1; step <= numberOfSplits; step++) {
        long long minValue = hasZeroes ? 0 : 1;
        long long maxValue = valueToSplit - (numberOfSplits - step) * minValue;
        maxValue = max(maxValue, minValue);
        long long value = rnd.next(minValue, maxValue);
        result.push_back(value);
        valueToSplit -= value;
    }
    shuffleVector(result);
    return result;
}

vector< long long > FolkaGenerator::generateVector(int sizeOfVector, long long elementLowerBound, long long elementUpperBound, bool printTheSample) {
    vector< long long > sample(sizeOfVector);
    for(int i = 0; i < sizeOfVector; i++) {
        sample[i] = rnd.next(elementLowerBound , elementUpperBound);
    }
    if(printTheSample) {
        printVector(sample);
    }
    return sample;
}
vector< int > FolkaGenerator::generatePermutationVector(int sizeOfVector, bool printTheSample) {
    vector< int > sample(sizeOfVector);
    vector< pair< int , int > > tmp(sizeOfVector);
    for(int i = 0; i < sizeOfVector; i++) {
        tmp[i].first = rnd.next(0 , (int)1e9);
        tmp[i].second = i + 1;
    }
    sort(tmp.begin() , tmp.end());
    for(int i = 0; i < sizeOfVector; i++) {
        sample[i] = tmp[i].second;
    }
    if(printTheSample) {
        printVector(sample);
    }
    return sample;
}

vector< vector< int > > FolkaGenerator::generateUnweightedTree(int numberOfNodes , bool printTheSample) {
    vector< vector< int > > sample;
    for(int x = 2; x <= numberOfNodes; x++) {
        int y = rnd.next(1 , x - 1);
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}
vector< vector< long long > > FolkaGenerator::generateWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
    vector< vector< long long > > sample;
    for(int x = 2; x <= numberOfNodes; x++) {
        int y = rnd.next(1 , x - 1);
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        sample.push_back({x, y, w});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}
vector< vector< long long > > FolkaGenerator::generateLinerWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
    vector< vector< long long > > sample;
    for(int x = 2; x <= numberOfNodes; x++) {
        int y = x - 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        sample.push_back({x, y, w});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateLinerUnweightedTree(int numberOfNodes, bool printTheSample) {
    vector< vector< long long > > sample;
    for(int x = 2; x <= numberOfNodes; x++) {
        int y = x - 1;
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< int > > FolkaGenerator::generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample) {
    vector< vector< long long > > tmp = generateUnconnectedWeightedGraph(numberOfNodes, minNumberOfEdges, maxNumberOfEdges, 0, 0, includeCycle, false);
    vector< vector< int > > sample;
    for(int i = 0; i < (int)tmp.size(); i++) {
        int x = tmp[i][0];
        int y = tmp[i][1];
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample) {
    vector< vector< long long > > sample;
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        while(!includeCycle && x == y) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        sample.push_back({x, y, w});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< int > > FolkaGenerator::generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool includeCycle, bool printTheSample) {
    vector< vector< long long > > tmp = generateConnectedWeightedGraph(numberOfNodes, minNumberOfEdges, maxNumberOfEdges, 0, 0, includeCycle, false);
    vector< vector< int > > sample;
    for(int i = 0; i < (int)tmp.size(); i++) {
        int x = tmp[i][0];
        int y = tmp[i][1];
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool includeCycle, bool printTheSample) {
    vector< vector< long long > > sample = generateWeightedTree(numberOfNodes, weightLowerBound, weightUpperBound, false);
    set< pair< int , int > > st;
    for(auto vec : sample) {
        st.insert({min(vec[0], vec[1]), max(vec[0], vec[1])});
    }
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = numberOfNodes - 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        while(x == y || st.find({min(x, y), max(x, y)}) != st.end()) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        st.insert({min(x, y), max(x, y)});
        sample.push_back({x, y, w});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

string FolkaGenerator::generateString(int length, string all) {
    string s;
    while((int)s.size() < length) {
        s += all[ rnd.next(0 , (int)all.size() - 1) ];
    }
    return s;
}
string FolkaGenerator::generateString(int length, char l, char r) {
    string all;
    while(l <= r){
        all += l;
        l++;
    }
    return generateString(length , all);
}
string FolkaGenerator::generateString(int length, vector< pair< char , char > > ranges) {
    string all;
    for(auto &[l , r] : ranges) {
        while(l <= r){
            all += l;
            l++;
        }
    }
    return generateString(length , all);
}

#endif //TESTGENRATOR_H
