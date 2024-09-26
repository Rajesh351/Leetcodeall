#include <map>
using namespace std;

class MyCalendar {
public:
    map<int, int> bookings;
    
    MyCalendar() {
        // Initialize empty map for bookings
    }
    
    bool book(int start, int end) {
        auto it = bookings.lower_bound(start);
        
        // Check if the new booking overlaps with the next booking
        if (it != bookings.end() && it->first < end) {
            return false; // There's a conflict with the next booking
        }
        
        // Check if the new booking overlaps with the previous booking
        if (it != bookings.begin() && prev(it)->second > start) {
            return false; // There's a conflict with the previous booking
        }
        
        // No conflicts, so insert the new booking
        bookings[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
