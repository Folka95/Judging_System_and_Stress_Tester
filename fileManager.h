#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;


const string dataPath = "..\\judgingData"s;
const string resultPath = "..\\judgingResults"s;
const string tempPath = "..\\temporaryData"s;

// Judging Results
const string stressResultsPath = resultPath + "\\stressResults"s;
const string sampleResultsPath = resultPath + "\\sampleResults"s;

// Sample Tests
const string sampleTestFolder = dataPath + "\\sampleTests"s;
const string fixedTestFolder = sampleTestFolder + "\\fixedTests"s;

// Temp System
const string exeFiles = tempPath + "\\exeFiles"s;

// Author Solution
const string authorSolutionFolder = dataPath + "\\authorSolution"s;
const string authorSolutionFile = authorSolutionFolder + "\\correctAuthorSolution.cpp"s;

// Testcase
const string testcaseGeneratorFolder = dataPath + "\\testCaseGenerator"s;
const string testcaseGeneratorFile = testcaseGeneratorFolder + "\\testCaseGenerator.cpp"s;

// contestants Solutions
const string contestantsSolutionsFolder = dataPath + "\\contestantsSolutions"s;

double runCppRW(const string &filePath, const string &inputFile, const string &outputFile);
double runCppR(const string &filePath, const string &outputFile);
double runCppW(const string &filePath, const string &inputFile);

void compile(const string &filePath);
string extractExe(const string &filePath);

bool deletePath(const string& path);
bool ensureFolderExists(const string& path);
bool ensureFileExists(const string& path);
bool copy(const string& src, const string& dest);

string getTime();

bool copy(const string& src, const string& dest) {
    try {
        ensureFileExists(dest);
        filesystem::copy_file(src, dest, filesystem::copy_options::overwrite_existing);
        return true;
    } catch (filesystem::filesystem_error &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return false;
}


string getTime() {
    auto now = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(
                       now.time_since_epoch()
                   ).count();
    return to_string(seconds);
}

bool deletePath(const string& path) {
    if (filesystem::exists(path)) {
        if (filesystem::is_directory(path)) {
            return filesystem::remove_all(path) > 0;
        }
        return filesystem::remove(path);
    }
    return false;
}
bool ensureFolderExists(const string& folderPath) {
    if (!filesystem::exists(folderPath)) {
        return filesystem::create_directories(folderPath);
    }
    return true;
}
bool ensureFileExists(const string& filePath) {
    try {
        filesystem::path p(filePath);
        filesystem::create_directories(p.parent_path());
        if (!filesystem::exists(p)) {
            ofstream file(p);
            if (!file) return false;
        }
        return true;
    }
    catch (filesystem::filesystem_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return false;
}

void compile(const string &filePath) {
    string exe = extractExe(filePath);
    string compileCmd = "g++ -std=c++20 " + filePath + " -o " + exe;
    system(compileCmd.c_str());
}

string extractExe(const string &filePath) {
    filesystem::path p(filePath);
    string exe = exeFiles + "\\"s + p.stem().string() + ".exe"s;
    return exe;
}

double runCppW(const string &filePath, const string &outputFile) {
    string runCmd = extractExe(filePath) + " > " + outputFile;
    auto start = high_resolution_clock::now();
    system(runCmd.c_str());
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

double runCppR(const string &filePath, const string &inputFile) {
    string runCmd = extractExe(filePath) + " < " + inputFile;
    auto start = high_resolution_clock::now();
    system(runCmd.c_str());
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

double runCppRW(const string &filePath, const string &inputFile, const string &outputFile) {
    string runCmd = extractExe(filePath) + " < " + inputFile + " > " + outputFile;
    auto start = high_resolution_clock::now();
    system(runCmd.c_str());
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

string replaceSpaces(const string& name) {
    string res = name;
    for (char &c : res)
        if (c == ' ')
            c = '_';
    return res;
}

void removeSpacesFromDirectories(const string &rootPathStr) {
    try {
        filesystem::path rootPath(rootPathStr);
        vector<filesystem::path> allPaths;

        for (auto& entry : filesystem::recursive_directory_iterator(rootPath)) {
            allPaths.push_back(entry.path());
        }

        sort(allPaths.begin(), allPaths.end(),
             [](const filesystem::path& a, const filesystem::path& b) {
                 return distance(a.begin(), a.end()) > distance(b.begin(), b.end());
             });

        for (auto& p : allPaths) {
            string filename = p.filename().string();

            if (filename.find(' ') != string::npos) {
                filesystem::path newPath = p.parent_path() / replaceSpaces(filename);
                filesystem::rename(p, newPath);
            }
        }

        string rootName = rootPath.filename().string();
        if (rootName.find(' ') != string::npos) {
            filesystem::path newRoot = rootPath.parent_path() / replaceSpaces(rootName);
            filesystem::rename(rootPath, newRoot);
        }

    } catch (...) {
        throw runtime_error("Error while removing spaces from directories");
    }
}

#endif //FILEMANAGER_H
