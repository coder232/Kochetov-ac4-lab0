#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
namespace LOG {
    // Enum to represent log levels
    enum LogLevel { DEBUG, INFO, WARNING, error, CRITICAL };

    class Logger {
    public:
        // Constructor: Opens the log file in append mode
        Logger(const string& filename)
        {
            logFile.open(filename, ios::app);
            if (!logFile.is_open()) {
                cerr << "error opening log file." << endl;
            }
        }

        // Destructor: Closes the log file
        ~Logger() { logFile.close(); }

        // Logs a message with a given log level
        void log(LogLevel level, const string& message)
        {
            // Get current timestamp
            time_t now = time(0);
            tm timeinfo;
            localtime_s(&timeinfo, &now);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp),
                "%Y-%m-%d %H:%M:%S", &timeinfo);

            // Create log entry
            ostringstream logEntry;
            logEntry << "[" << timestamp << "] "
                << levelToString(level) << ": " << message
                << endl;

            // Output to console
            cout << logEntry.str();

            // Output to log file
            if (logFile.is_open()) {
                logFile << logEntry.str();
                logFile
                    .flush(); // Ensure immediate write to file
            }
        }

    private:
        ofstream logFile; // File stream for the log file

        // Converts log level to a string for output
        string levelToString(LogLevel level)
        {
            switch (level) {
            case DEBUG:
                return "DEBUG";
            case INFO:
                return "INFO";
            case WARNING:
                return "WARNING";
            case error:
                return "error";
            case CRITICAL:
                return "CRITICAL";
            default:
                return "UNKNOWN";
            }
        }
    };
}

