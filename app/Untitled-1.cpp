#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    int day;
    string month;
    int year;
};

bool compareDates(const Date& a, const Date& b) {
    // Prioritize year comparison
    if (a.year != b.year) {
        return a.year < b.year;
    }

    // If years are equal, compare months
    if (a.month != b.month) {
        // Map months to numbers for comparison
        const vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int monthAIndex = find(months.begin(), months.end(), a.month) - months.begin();
        int monthBIndex = find(months.begin(), months.end(), b.month) - months.begin();
        return monthAIndex < monthBIndex;
    }

    // If years and months are equal, compare days
    return a.day < b.day;
}

vector<string> sortDates(vector<string> dates) {
    vector<Date> dateObjects;
    for (const string& dateStr : dates) {
        Date date;
        // Extract day, month, and year using stringstream or sscanf
        stringstream ss(dateStr);
        ss >> date.day >> date.month >> date.year;
        dateObjects.push_back(date);
    }

    sort(dateObjects.begin(), dateObjects.end(), compareDates);

    // Convert back to string format
    vector<string> sortedDates;
    for (const Date& date : dateObjects) {
        stringstream ss;
        ss << date.day << " " << date.month << " " << date.year;
        sortedDates.push_back(ss.str());
    }

    return sortedDates;
}

int main() {
    vector<string> dates = {"01 Mar 2017", "03 Feb 2017", "15 Jan 1998"};
    vector<string> sortedDates = sortDates(dates);

    for (const string& date : sortedDates) {
        cout << date << endl;
    }

    return 0;
}
