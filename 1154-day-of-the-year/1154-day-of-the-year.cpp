class Solution {
public:
    int dayOfYear(string date) {

        // Days in each month (non-leap year)
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

        // Extract year
        string year=date.substr(0,4);

        // Extract month (01-12)
        int month=stoi(date.substr(5,2));

        // Extract day
        string day=date.substr(8);

        int dayse=0;

        // Add days of previous months
        // month-1 because array is 0-indexed
        for(int i=0;i<month-1;i++){
            dayse+=days[i];
        }

        // Add current day
        dayse+=stoi(day);

        int y = stoi(year);

        // Check proper leap year condition
        if((y%4==0 && y%100!=0) || (y%400==0)){
            // Add 1 day if leap year and month after Feb
            if(month>2) dayse+=1;
        }

        return dayse;
    }
};
