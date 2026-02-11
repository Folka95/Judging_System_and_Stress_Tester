#include <bits/stdc++.h>
#include "fileManager.h"
using namespace std;

// Problem Constraints :
const double timeLimit = 1000 * 1.05; // ms (Recommended to use factor like '1.05' to be in safe zone)
const int stressTestCount = 100; // Number of stress tests done (Stop on first wrong answer on stress tests ONLY)
const bool stopOnTimeLimit = false; // Break on Time limit (Sample not affected)
const bool saveAllTestsLogs = false; // Save all test results


void initialize();
void exit();
bool validateSolution(const string &answerFilePath, const string &filePath);

struct Solution {
    string fileName;
    double time;
    bool AC;
};

bool runTest(const string &testFile, const string &testName, const string &savePath) {
    ensureFileExists(savePath + "\\Author.txt"s);
    Solution jans("Author", runCppRW(authorSolutionFile, testFile, savePath + "\\Author.txt"s), true);
    vector< Solution > sols;
    sols.push_back(jans);
    const string answerFilePath = savePath + "\\Author.txt"s;
    for (const auto& entry : filesystem::directory_iterator(contestantsSolutionsFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            string solutionName = entry.path().stem().string();
            const string destination = savePath + "\\"s + solutionName + ".txt"s;
            ensureFileExists(destination);
            sols.push_back({solutionName,
            runCppRW(solutionName, testFile, destination),
            validateSolution(answerFilePath, destination)});
        }
    }
    bool isWA = false;
    bool bad = false;
    for(auto &[fileName, time, AC] : sols) {
        cout << testName << string(3, ' ') << "| ";
        cout << fileName << string(3, ' ') << "| ";
        cout << (AC ? "AC" : "WA") << string(3, ' ') << "| ";
        cout << time << "ms" << string(3, ' ');
        if(time > timeLimit) {
            cout << " (time limit exceeded)";
            if(stopOnTimeLimit) {
                isWA = true;
            }
            bad = true;
        }
        cout << endl;
        isWA |= !AC;
        bad |= isWA;
    }
    if(!saveAllTestsLogs) {
        if(!bad) {
            deletePath(savePath);
        }
    }
    cout << string(50, '-') << endl;
    return isWA;
}

void runStress() {
    cout << " Stress Name | Solution Name | Verdict | Execution Time " << endl;
    for(int stressCounter = 1; stressCounter <= stressTestCount; stressCounter++) {
        const string testName = "test_"s + to_string(stressCounter);
        const string savePath = stressResultsPath + "\\"s + testName;
        const string testPath = savePath + "\\"s + testName + ".txt"s;
        ensureFileExists(testPath);
        runCppW(testcaseGeneratorFile, testPath);
        if(runTest(testPath, testName, savePath)) {
            return;
        }
    }
}

void runSample() {
    cout << " Sample Path | Solution Name | Verdict | Execution Time " << endl;
    for (const auto& entry : filesystem::recursive_directory_iterator(sampleTestFolder)) {
        if (entry.is_regular_file()) {
            const string testPath = entry.path().string();
            const string testName = entry.path().stem().string();
            const string testRelativePath = filesystem::relative(entry.path().parent_path(), sampleTestFolder).string();
            const string savePath = sampleResultsPath + "\\"s + testRelativePath + "\\"s + testName;
            runTest(testPath, testName, savePath);
        }
    }
}

int main() {
    auto displayLoadingBlock = [](const string &output) {
        int len = output.size();
        cout << string(len + 8, '-') << endl;
        cout << "|   " << output << "   |" << endl;
        cout << string(len + 8, '-') << endl;
    };

    displayLoadingBlock("Welcome to Folka judging system and stress tester!");

    displayLoadingBlock("Removing spaces from directory paths...");
    removeSpacesFromDirectories(dataPath);

    displayLoadingBlock("Initializing environment...");
    initialize();

    displayLoadingBlock("Running sample tests...");
    runSample();

    displayLoadingBlock("Running stress tests...");
    runStress();

    displayLoadingBlock("Exiting the app...");
    exit();
    cout << "It is working!";
    return 0;
}

void initialize() {
    deletePath(tempPath);
    deletePath(resultPath);

    ensureFolderExists(tempPath);
    ensureFolderExists(resultPath);

    ensureFolderExists(exeFiles);
    ensureFolderExists(sampleResultsPath);
    ensureFolderExists(stressResultsPath);


    compile(testcaseGeneratorFile);
    compile(authorSolutionFile);
    for (const auto& entry : filesystem::directory_iterator(contestantsSolutionsFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            compile(entry.path().string());
        }
    }
}

void exit() {
    deletePath(tempPath);
}

bool validateSolution(const string &answerFilePath, const string &filePath) {
    auto clean = [](const string &filename) {
        ifstream file(filename);
        vector<string> tokens;
        string word;
        while (file >> word) { // operator>> skips spaces automatically
            tokens.push_back(word);
        }
        return tokens;
    };
    vector<string> jans = clean(answerFilePath);
    vector<string> cans = clean(filePath);
    return jans == cans;
}

