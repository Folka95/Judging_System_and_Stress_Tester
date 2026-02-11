#ifndef TESTGENRATOR_H
#define TESTGENRATOR_H
#include <bits/stdc++.h>
using namespace std;

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
    // Printing functions
    static void printVector(auto myVec);
    static void printGraph(auto myUGraph);
public:
    // Generating Vectors
    static vector< long long > generateVector(int sizeOfVector, long long elementLowerBound, long long elementUpperBound, bool printTheSample);
    static vector< int > generatePermutationVector(int sizeOfVector, bool printTheSample);

    // Generating Trees
    static vector< vector< int > > generateUnweightedTree(int numberOfNodes , bool printTheSample);
    static vector< vector< long long > > generateWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample);
    static vector< vector< long long > > generateLinerWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample);

    // Generating Unconnected Graphs
    static vector< vector< int > > generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample);
    static vector< vector< long long > > generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample);

    // Generating Connected Graphs
    static vector< vector< int > > generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample);
    static vector< vector< long long > > generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample);

    // Generating Directed Graphs
    static vector< vector< int > > generateDirectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample);
    static vector< vector< long long > > generateDirectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample);

    // Generating Strings
    static string generateString(int length, string all);
    static string generateString(int length, char l, char r);
    static string generateString(int length, vector< pair< char , char > > ranges);
};

// Implementation
void FolkaGenerator::printVector(auto myVec) {
    for(int i = 0; i < (int)myVec.size(); i++) {
        cout << myVec[i];
        if(i + 1 < (int)myVec.size()) {
            cout << ' ';
        }
    }
}

void FolkaGenerator::printGraph(auto myUGraph) {
    for(int i = 0; i < myUGraph.size(); i++) {
        for(int j = 0; j < myUGraph[i].size(); j++) {
            cout << myUGraph[i][j];
            if(j + 1 < myUGraph[i].size()) {
                cout << " ";
            }
        }
        if(i + 1 < myUGraph.size()) {
            cout << endl;
        }
    }
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

vector< vector< int > > FolkaGenerator::generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
    vector< vector< int > > sample;
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        while(x == y) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
    vector< vector< long long > > sample;
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        while(x == y) {
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

vector< vector< int > > FolkaGenerator::generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
    vector< vector< int > > sample = generateUnweightedTree(numberOfNodes, false);
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = numberOfNodes - 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        while(x == y) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        sample.push_back({x, y});
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
    vector< vector< long long > > sample = generateWeightedTree(numberOfNodes, weightLowerBound, weightUpperBound, false);
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    for(int i = numberOfNodes - 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        while(x == y) {
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

vector< vector< int > > FolkaGenerator::generateDirectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
    vector< vector< int > > sample;
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    set< int > st[numberOfNodes + 1];
    for(int i = 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        while(x == y || st[x].find(y) != st[x].end()) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        sample.push_back({x, y});
        st[x].insert(y);
    }
    if(printTheSample) {
        printGraph(sample);
    }
    return sample;
}

vector< vector< long long > > FolkaGenerator::generateDirectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
    vector< vector< long long > > sample;
    int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
    set< int > st[numberOfNodes + 1];
    for(int i = 1; i <= m; i++) {
        int x = 1;
        int y = 1;
        long long w = rnd.next(weightLowerBound , weightUpperBound);
        while(x == y || st[x].find(y) != st[x].end()) {
            x = rnd.next(1 , numberOfNodes);
            y = rnd.next(1 , numberOfNodes);
        }
        sample.push_back({x, y, w});
        st[x].insert(y);
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

// class FolkaGenerator {
// public:
//     // Printing functions
//      void printVector(auto myVec) {
//          for(int i = 0; i < (int)myVec.size(); i++) {
//              cout << myVec[i];
//              if(i + 1 < (int)myVec.size()) {
//                  cout << ' ';
//              }
//          }
//      }
//     void printGraph(auto myUGraph) {
//         for(int i = 0; i < myUGraph.size(); i++) {
//             for(int j = 0; j < myUGraph[i].size(); j++) {
//                 cout << myUGraph[i][j];
//                 if(j + 1 < myUGraph[i].size()) {
//                     cout << " ";
//                 }
//             }
//             if(i + 1 < myUGraph.size()) {
//                 cout << endl;
//             }
//         }
//     }
//
//     // Generating Vectors
//     vector< long long > generateVector(int sizeOfVector, long long elementLowerBound, long long elementUpperBound, bool printTheSample) {
//         vector< long long > sample(sizeOfVector);
//         for(int i = 0; i < sizeOfVector; i++) {
//             sample[i] = rnd.next(elementLowerBound , elementUpperBound);
//         }
//         if(printTheSample) {
//             printVector(sample);
//         }
//         return sample;
//     }
//     vector< int > generatePermutationVector(int sizeOfVector, bool printTheSample) {
//         vector< int > sample(sizeOfVector);
//         vector< pair< int , int > > tmp(sizeOfVector);
//         for(int i = 0; i < sizeOfVector; i++) {
//             tmp[i].first = rnd.next(0 , (int)1e9);
//             tmp[i].second = i + 1;
//         }
//         sort(tmp.begin() , tmp.end());
//         for(int i = 0; i < sizeOfVector; i++) {
//             sample[i] = tmp[i].second;
//         }
//         if(printTheSample) {
//             printVector(sample);
//         }
//         return sample;
//     }
//
//     // Generating Trees
//     vector< vector< int > > generateUnweightedTree(int numberOfNodes , bool printTheSample) {
//         vector< vector< int > > sample;
//         for(int x = 2; x <= numberOfNodes; x++) {
//             int y = rnd.next(1 , x - 1);
//             sample.push_back({x, y});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//     vector< vector< long long > > generateWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
//         vector< vector< long long > > sample;
//         for(int x = 2; x <= numberOfNodes; x++) {
//             int y = rnd.next(1 , x - 1);
//             long long w = rnd.next(weightLowerBound , weightUpperBound);
//             sample.push_back({x, y, w});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//     vector< vector< long long > > generateLinerWeightedTree(int numberOfNodes, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
//         vector< vector< long long > > sample;
//         for(int x = 2; x <= numberOfNodes; x++) {
//             int y = x - 1;
//             long long w = rnd.next(weightLowerBound , weightUpperBound);
//             sample.push_back({x, y, w});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     // Generating Unconnected Graphs (no self loop)
//     vector< vector< int > > generateUnconnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
//         vector< vector< int > > sample;
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         for(int i = 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             while(x == y) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     vector< vector< long long > > generateUnconnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
//         vector< vector< long long > > sample;
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         for(int i = 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             long long w = rnd.next(weightLowerBound , weightUpperBound);
//             while(x == y) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y, w});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     // Generating Connected Graphs (no self loop)
//     vector< vector< int > > generateConnectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
//         vector< vector< int > > sample = generateUnweightedTree(numberOfNodes, false);
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         for(int i = numberOfNodes - 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             while(x == y) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     vector< vector< long long > > generateConnectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
//         vector< vector< long long > > sample = generateWeightedTree(numberOfNodes, weightLowerBound, weightUpperBound, false);
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         for(int i = numberOfNodes - 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             long long w = rnd.next(weightLowerBound , weightUpperBound);
//             while(x == y) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y, w});
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     // Generating Directed Graphs (no self loop)
//     vector< vector< int > > generateDirectedUnweightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, bool printTheSample) {
//         vector< vector< int > > sample;
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         set< int > st[numberOfNodes + 1];
//         for(int i = 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             while(x == y || st[x].find(y) != st[x].end()) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y});
//             st[x].insert(y);
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     vector< vector< long long > > generateDirectedWeightedGraph(int numberOfNodes, int minNumberOfEdges, int maxNumberOfEdges, long long weightLowerBound, long long weightUpperBound, bool printTheSample) {
//         vector< vector< long long > > sample;
//         int m = rnd.next(minNumberOfEdges, maxNumberOfEdges);
//         set< int > st[numberOfNodes + 1];
//         for(int i = 1; i <= m; i++) {
//             int x = 1;
//             int y = 1;
//             long long w = rnd.next(weightLowerBound , weightUpperBound);
//             while(x == y || st[x].find(y) != st[x].end()) {
//                 x = rnd.next(1 , numberOfNodes);
//                 y = rnd.next(1 , numberOfNodes);
//             }
//             sample.push_back({x, y, w});
//             st[x].insert(y);
//         }
//         if(printTheSample) {
//             printGraph(sample);
//         }
//         return sample;
//     }
//
//     // Generating strings
//     string generateString(int length, string all) {
//         string s;
//         while((int)s.size() < length) {
//             s += all[ rnd.next(0 , (int)all.size() - 1) ];
//         }
//         return s;
//     }
//     string generateString(int length, char l, char r) {
//         string all;
//         while(l <= r){
//             all += l;
//             l++;
//         }
//         return generateString(length , all);
//     }
//     string generateString(int length, vector< pair< char , char > > ranges) {
//         string all;
//         for(auto &[l , r] : ranges) {
//             while(l <= r){
//                 all += l;
//                 l++;
//             }
//         }
//         return generateString(length , all);
//     }
// };

#endif //TESTGENRATOR_H
