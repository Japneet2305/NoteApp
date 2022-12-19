#include<bits/stdc++.h>
#include<time.h>
using namespace std;

string editable = "start https://www.notion.so/personalcalender/";
string readable = "start https://personalcalender.notion.site/";

bool dateCompare(string &DateTime){

        time_t timeNow = time(0);
        tm *dateTimeNow = localtime(&timeNow);
        string currDay = to_string(dateTimeNow->tm_mday);
        string currMonth = to_string(dateTimeNow->tm_mon + 1);
        string DateTime_Date = "";
        string DateTime_Month= "";
        int i = 0;
        for(auto it : DateTime){
            if(it=='/'){
                i++;
            }else{
                if(i==0) DateTime_Date.push_back(it);
                else if(i==1) DateTime_Month.push_back(it);
            }
        }

        return ((currDay == DateTime_Date) && (currMonth == DateTime_Month));
        // return true;
}

bool isLeapYear(){

    int year;
    time_t timeNow = time(0);
    tm *dateTimeNow = localtime(&timeNow);
    int currYear = dateTimeNow->tm_year;
   // leap year if perfectly divisible by 400
   if (currYear % 400 == 0) {
      return true;
   }
   // not a leap year if divisible by 100
   // but not divisible by 400
   else if (currYear % 100 == 0) {
      return false;
   }
   // leap year if not divisible by 100
   // but divisible by 4
   else if (currYear % 4 == 0) {
      return true;
   }
   // all other years are not leap years
   else {
      return false;
   }
}

int trimmedMonth(string &date){
    // int DateTime_Date = 0;
    int DateTime_Month= 0;
    int i = 0;
    for(int j = 0 ; j < date.length() ; j++){

        if(date[j]=='/'){
            i++;
        }else{
            if(i==1){
                DateTime_Month *= 10;
                DateTime_Month += int(date[j] - '0');
            }
        }

    }
    // cout<<DateTime_Month<<" ";
    return DateTime_Month;
}

int trimmedDay(string &date){
    int DateTime_Date = 0;
    // int DateTime_Month= 0;
    int i = 0;
    for(int j = 0 ; j < date.length() ; j++){

        if(date[j]=='/'){
            i++;
        }else{
            if(i==0){
                DateTime_Date *= 10;
                DateTime_Date += int(date[j] - '0');
            }
        }

    }
    // cout<<DateTime_Date<<" ";
    return DateTime_Date;
}       

class Day{
    public: // try making this private too.

    int dayNo;
    string Date;

    private:

        string Edit_Link;// Editable link
        string Read_Link;// View only and commentable link
        string last_editted;  // When was this day diary last editted.
        vector<string> Events; //Holidays , Birthdays , Events

    public:
        Day(){}

        Day(int d , string &day_link);

        string Get_Day_link(string &date){
            Date = date;
            time_t current_time; // For outputting when last time entered
            time(&current_time); // Will save this in the day's last editted.
            last_editted = ctime(&current_time);

            if (dateCompare(date)){
                return Edit_Link;
            }else{
                return Read_Link;
            }
        }
        
        string Get_Day_link(){
            return Edit_Link;
        }

        string get_last_visted(){
            return last_editted;
        }

        string photos_datelink(int &day , int &month){
            string sDay = to_string(day);
            string sMonth = to_string(month);
            string link = "start https://photos.google.com/search/";
            link = link + sMonth;
            link = link + "%2F";
            link = link + sDay;
            return link;
        }

        string photos_search_link(string &event){
            string link = "start https://photos.google.com/search/";
            link = link + event;
            return link;
        }

        void Set_events(string &s){
            Events.push_back(s);
        }

        void get_events(){
            if(Events.size()==0){
                cout<<"No Events Here..."<<endl;
            }else{
                for(auto i : Events){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }
};

class Month{

    string MonthName;
    int noOfDays;
    // Day* DayArray;
    public:
        Day *DayArray;
        Month(){}
        Month(int d , string s){
            noOfDays = d;
            MonthName = s;
            DayArray = new Day[d];
        }
};

Day :: Day(int d , string &day_link){
        dayNo = d+1;
        Edit_Link = editable + day_link;
        Read_Link = readable + day_link;
}

void Setup_January(Month *MonthArray){

    string day_link;
    day_link = "1st-January-4cfe5a00536c451f8cffb5cb68bb954e";
    MonthArray[0].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-January-a4e5ff3711c047d7a0764b8dec428244";
    MonthArray[0].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-January-4ef328a1203847e7b97c068c4a01e2b7";
    MonthArray[0].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-January-55fac0d6c4834a3e96e3e667af022420";
    MonthArray[0].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-January-92938be8a29a4d7a984a02c14b0efe74";
    MonthArray[0].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-January-7dfe40ac0e014692bd6230dc080cbe1d";
    MonthArray[0].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-January-eb67bb96b09c43a7be9c4dd58db250c0";
    MonthArray[0].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-January-09f186d84d364d7da1427deb8ff55b0c";
    MonthArray[0].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-January-a6823147863f4eff9d5f1bee07993e95";
    MonthArray[0].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-January-1122d78c4cc5497c86d6cb02a21ea9d7";
    MonthArray[0].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-January-83883012806a4e07a6a9cd3f04075fd2";
    MonthArray[0].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-January-4868e2f700634f068bfb24563c29a39f";
    MonthArray[0].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-January-f8ba76c9cfec4ad7a1fecb5767059c4f";
    MonthArray[0].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-January-ef2c3417ca7a4aab88f5c53fa372b179";
    MonthArray[0].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-January-05e94a96fc3241439ea307a88a95bad4";
    MonthArray[0].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-January-fae477e3875e44bd9effac4c0e49af37";
    MonthArray[0].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-January-db2c696a0c01447eb35c5f2eb02401e8";
    MonthArray[0].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-January-5af3aa2fc3254684a8fb956628ad8c0b";
    MonthArray[0].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-January-77005066242b46a58c0605c9351a9f2d";
    MonthArray[0].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-January-c51a63f467f54068b38f69cd34e0bc37";
    MonthArray[0].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-January-61561a49da184a12ad72aedee4889a33";
    MonthArray[0].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-January-1716b8c762294d2ba62676c664175b0a";
    MonthArray[0].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-January-29a825095c2b43d494bc4ce16f4f569d";
    MonthArray[0].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-January-fe6a9f692d014e22b55194863e994b75";
    MonthArray[0].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-January-6fffa855a4844b10bce00dfb5f70b79b";
    MonthArray[0].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-January-6486d4acbbb34dd181bdda2d12fdb8a8";
    MonthArray[0].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-January-49d60e34dfd943baa941a394ac7550a0";
    MonthArray[0].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-January-bd0bf413a905416a840d59cea0c9ca74";
    MonthArray[0].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-January-fcbfe605bd15499683001eb608de1c92";
    MonthArray[0].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-January-591a4184ea074ee6b3265d2476094849";
    MonthArray[0].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-January-cbc554c0c0674bce9ba5a334870a6015";
    MonthArray[0].DayArray[30] = Day( 30, day_link );
}

void Setup_February(Month *MonthArray){
//have to check if leap in both setup month function as well as here
    string day_link;
    int M = 1;
    day_link = "1st-February-56db2059612d4cb39192aa4665a394ed";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-February-551742f8114242ab8023176345dd20c7";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-February-cd6ba2b832734cc787661de535fdf66f";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-February-34dee32dc02b4d0caaa578ffbc4f23ff";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-February-1afc782d8277451183c228b64ef1e89d";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-February-02d1c7b9e2914b4a9d665032d9219201";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-February-4c45d6eaa7d14c498ef1bb2dbd6a06d4";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-February-3e177f8cc0b04da08e14044ea04e990e";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-February-eecd488b19e645fa8b57b16cfcefe56d";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-February-fd4fa9cd43bb4a3e8b6aa9c5a66ca420";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-February-53abdcb3e7724d5eb27e5d3e1c75c783";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-February-f4f7928179394a0f926df25573505da0";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-February-f972cccafede4abe9add466da2cb84e8";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-February-1c4722169a36468c8af1b168a34b97d3";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-February-5ee3327ccf3a4bb3bd45e770a64fcd65";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-February-00d6b9ee2f204a8196ed1cb3c59d8117";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-February-554d913091ca41f5b0829bab55f703f7";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-February-8da04684ef0c4a598e88ba5569433af7";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-February-eff140872b5a415394836ca54b4ca780";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-February-bdef4acb0dcf47edb3aca5f856a3ecb6";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-February-2966719d32ec4420a489bf918007c13b";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-February-3ff5330b00ff427e8a5f8ae9ed95d8ae";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-February-fa81974d7ebe418a8baef46e3a12302a";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-February-5caa90f4feb14bcb8c75f52ab9cfad8f";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-February-29e86a6a5f7f4150a538d38bd3ae5520";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-February-f4266fca680b4cf0ac7e6b3a5f0f7304";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-February-e9903888d80841b1b89881e905a80010";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-February-b89859ef50af45258e29d05ab3cc52f0";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //29th Feb
    if(isLeapYear){
        day_link = "29th-February-09290107e4e2495c9c20b3aff0c2ad6c";
        MonthArray[M].DayArray[28] = Day( 28, day_link );
    }
}

void Setup_March(Month *MonthArray){
    string day_link;
    int M = 2;
    day_link = "1st-March-61cdba3874c74e85adcb74a2186abbea";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-March-c4ae90fa3d164c8c821ff79e77eba666";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-March-a897674cc91249e9b800e686adfb9e78";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-March-8c1f75f8139d4639832f695f4b6e0685";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-March-fe3b4dd1911a450c8ba545e1c3d0b2d8";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-March-d8fac41b16864a09a0a16afadab89220";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-March-624d1379edf64644b51cdab8b5bdab70";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-March-5c0facc0e8c54069812913b4bf929dd3";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-March-45e89cf814bd4ca891a3903ce4dc485d";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-March-b84062315d6f4a1a9024e37c9d5c5673";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-March-7931b068625e4283a7c283266be6f6bb";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-March-49b43b0b55b3416a91ba7c156f7eb4b6";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-March-e3e9bb16f23341698208c8b6f0940a7e";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-March-dbbbc2356f2d43fdb44db6b9edb607ca";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-March-63a80e5fff574a6b9bf3de9b40ead212";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-March-8ba34ede707b408da775be2848357a39";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-March-79f764778f294b2c81f5ce04c1963fe4";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-March-374f4af6575f4406b7d01a3866650d8a";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-March-d2c91bcc42b64dd2a1cb147507c87b2b";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-March-7dc03148b3b34e8aa2e5013b113c8a6b";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-March-47fac1c5685b494aa077fed7ad84cfcf";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-March-65f6ea8f07e54db0aecac6bbf0f1d3d4";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-March-ac068ef82fb14c53ac88ff9155f4e44d";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-March-0ca1adae312b490f83f20e1111c45499";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-March-8bbec6391fad483694b610b6b44c0d7a";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-March-c06ca3deb07841f1bbaf5aca03e7f956";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-March-c35f87f5776440ff86a556f1c3da611f";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-March-05dcf764a0f74e6189903ab8cf0c88a2";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-March-c641535f8c5642de8a261071df19a0f5";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-March-5f3ed419811c4638a84951c2b0873da4";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-March-c99537c39be6473a9784226716988a3c";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_April(Month *MonthArray){
    string day_link;
    int M = 3;
    day_link = "1st-April-ec17109a4c0241ebbed808100293b12c";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-April-9213750e49a24d7eb3964b79be084802";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-April-56560570e4614a199b66b32184466336";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-April-71e6434af3e84cff9563fb9dcdbaff00";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-April-543bb8a928d84811b01f2cd19de9ca4e";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-April-66bba616ae714a4daafedfc1c7f315b2";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-April-f4c084b45d454f61b047f1d0b5d07347";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-April-e1a73cb31dca4000a718ad187a967bb9";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-April-739c8e3437324d0ca69a6e194e51f74d";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-April-91c7c06f47144021841352e4098126ec";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-April-e709958e43b149a1b76276ea5aca9277";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-April-8d1afcdf767a499e980e691ac88091b7";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-April-25967479781f401da71dd6bfe017c357";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-April-0e259cd8c8e844929b20d10c04bddbb0";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-April-2dec4668976b4fab97ccf1f61d610380";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-April-8b3a97ded7604de9af46d331a7f2afe6";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-April-872a4a3d4eca4afb8b96c9c7e2df183a";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-April-efd88a9b254c4575aa6e16c26177a35a";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-April-c1ed32561bf54f1ca33b5c18146b2b86";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-April-6d4223c5d75c473f9562166dcf0c76dc";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-April-18aa53dca45341c98fa252d4ab682d70";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-April-7c006eb1c842442aa9c771e5e41abf57";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-April-fdc6a7d685244e17b10026a611f3ff8f";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-April-33c33b4709d842fd81904e8837869049";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-April-24d17898761c4a20956fddb19943fbd0";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-April-a4be7cf0e9ce4d3a8e789b07aeb416aa";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-April-d2a36ff19e7c416fbc369c2b29c8758d";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-April-71a9bc14f5be4f28ac285eb3b14e1469";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-April-45b1252c14824d928f72a92c8d351d74";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-April-fe9a895fc8b944c5b5406ae932d1e8ff";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
}

void Setup_May(Month *MonthArray){
    string day_link;
    int M = 4;
    day_link = "1st-May-5f31fb729c2444dea4de33dadc84c154";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-May-2e1d83acf6bb426f85fad0fb781e1f0a";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-May-c20daa75f8d148efbe714baa6b49b3e5";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-May-a4853c3851fe468289ec6a42879e7748";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-May-76a45daab80149349aff7584cecf839c";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-May-f1783f68bab74e45af116804b7c57888";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-May-ff04b1a7cf0f4ffab1a8ddaddbb0a794";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-May-c2423a247f6a48318c5dbb526f7c3913";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-May-52d40bb985984b199e9ee6243bb66455";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-May-33dd35ebebd94afb97bb20bef8a0d8b0";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-May-976964c9f47d40a7a4bf16f862fdfa51";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-May-2f2af2988af947ca91f4ffecbc5289a7";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-May-c6fd353a1a12437a87a91813ec7613a6";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-May-e561296f335c4f77ac3094f54fccdfb7";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-May-22549d30c62444faace56f9d19653c74";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-May-c0221380b61b4a00be629069f5325a62";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-May-95bd821f827d4e0186ba008ea155abb0";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-May-9107c0729ebe41d7b82ea04f71d7d1bf";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-May-1e8ebcb83d3f433d95779cd38b6ae68c";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-May-922b7055f37b44459a5bf94ad59ef77e";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-May-82cd6f40b8c147f09c7066576bd98a6b";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-May-0356b8cd3a3642bdb8ee79d70791d377";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-May-2ed561a5754b477b8d9936cdaf2c3a5d";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-May-58625ccc0b4c4aa4bd2c99f122869b7e";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-May-225ff2c1a8284aaeaf7a8ea7e186d2a1";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-May-5136d687ee0447cbb2140c19002e0c26";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-May-552cf53e282949b18cbbd7e1b4119352";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-May-ba93ea9428d64c26bda0c588f60fd097";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-May-24afbd4b62d24379a07555a2138c2680";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-May-56512d9ea5054df6bdfa01efaefea280";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-May-bd66f2f7be3c4e978d33e2c9d25ff91b";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_June(Month *MonthArray){
    string day_link;
    int M = 5;
    day_link = "1st-June-5c0bafe2b6dd4888aa533c0ac28cb466";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-June-4eece0bee0ae4a56a0b3d2c5bd0fa3eb";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-June-3fcfe56841e44d14a93fc2f6bc43e82d";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-June-2b41548794784a34b237890e0b6bed65";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-June-1f827035e7ef412f89b36b6b56836548";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-June-cace25d995444099880a558a92021ddf";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-June-d702e01ac54d4184a02f75645d0a3a6e";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-June-26eef27bc5b548aa9c7e499453a065f4";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-June-399ed21865f74edead3f96eb53ca9ac3";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-June-8573a154c1b9455fa137f077771c6025";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-June-f5b990384245445b9733d5a4c8646d81";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-June-9459ed98944c410a8c88972089fa1996";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-June-e9a6036d1dbc43dc8ba646674855f1c6";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-June-810cd773be9c43a0b89dc327a4c4fd12";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-June-ceb06b303044411294724bc26a5f41b6";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-June-a954420890f54aa29cd85c74eb5c19ea";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-June-4bc39154fff0422aaa3cd1be041d9901";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-June-c5b67604ef20412ba21ab465c8c7ea7c";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-June-061025ca61e449c385aff3785faf7118";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-June-cee8053f0c1f4c2dbd0308d7780dc849";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-June-1331ee55b2c74619ad49d2b0a699eb04";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-June-6ee52d130dc8458ea6d1e844297a5494";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-June-1ff2753f58e6426d965914b6118e1148";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-June-10052c7f1e9641efa01f82391c1a22ab";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-June-14ab0939ade34b159eb0633d2df07d97";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-June-f938409ffdc243daa36d768ad6b64ca5";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-June-620fbb348c8e4cbf9c309de60dfbb872";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-June-4d448c38992e489fba9c0ed0ed95eb40";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-June-93c7b59032634a848c1676de13f12ea3";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-June-381cae8972fa4ab09d574d2f0bbc97aa";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
}

void Setup_July(Month *MonthArray){
    string day_link;
    int M = 6;
    day_link = "1st-July-8443674579334ac8aa577ce0114ad2fd";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-July-7a49420612814d88a3faaf5e48364115";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-July-e225b91049d14281906effc8327d4892";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-July-d3c2f1cdc4454d53a6c833fa363fd766";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-July-a1672a45f6ba442ab6e37a4f25e57c64";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-July-94a76887f0c74700b2ca66b9f152c45d";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-July-e6034373fa0c46febc8ffea0e3bb5770";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-July-caa13c9526814978ae15e82d01599229";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-July-f846f446b7f74158b8f1efd1ac6efaaf";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-July-40885c75b51849e393b886c46db80255";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-July-f74d4bb4992148f3a5a20d5974a8a364";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-July-7dd06be2ae0848ca985e563eb9ee7d97";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-July-50f2a622e6b543a1a6bd81ba36a7f2e8";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-July-b5aec280686845f18f2a3f84d2efeb10";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-July-12a4c90684074f7381f9fef97b81272f";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-July-f5abaa0aa5984b37b1c7cb2d5cfe92db";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-July-01014bedf7464a589e03ce7a7c9ee3fe";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-July-be2aa3a53e9640b69d908a8c1d2dd7a5";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-July-ebbf71046efa4e81837f00614453d512";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-July-747b64313a43408ba186fec888d337b5";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-July-3ce46497f8ae44e8b7c8d15446b21da3";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-July-575a01a8dc9e48c88586c6166a6cb042";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-July-130fd795e96d41f6a72a3353cac3836a";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-July-645bd1e7acf5404dafd90f153949a094";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-July-6137179dd0b14be0a3156aed5d4577f9";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-July-3e738646a8ee49479943a2c2d58b604d";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-July-13b9a2cc11b74c74a6cd5f1916d32add";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-July-c3564e48b84f459c8cd9d60efa893a06";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-July-f6cc88307ef64d8a91d6f003909dba11";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-July-32fd99976da64808bd29fff38ef0c1f4";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-July-ffad9e88f48a43b494679e7c5441a85f";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_August(Month *MonthArray){
    string day_link;
    int M = 7;
    day_link = "1st-August-ed49913ddee2408fa7ca2fad62612e00";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-August-450cf52b19964f19946a5f0519e8354b";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-August-e155da6c0305464eb4c3723149e6d0b7";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-August-b0cd3909a0b24b9d8c5f9f03d452fada";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-August-68317326759e447bb0d205551ceee0bc";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-August-5174cc853f904e5985aae03c97705d98";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-August-711dfd634af84db9b954da3e54ebf5e7";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-August-9ac83f36e8f847eda6bb5cac40289c51";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-August-f3e69443aa9a4cad80eb6e7bb62a2024";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-August-25dd785ddcef4df787242372107c5582";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-August-b294607246004f009401974e814cff3a";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-August-0975f0260daf4f1791790e71dfea6899";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-August-563988edaaaa40669e13a194e20dd983";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-August-e4a3760f613a4d3d946c9fde4113c2f5";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-August-cdf20d9dd08a42e8adf83cb0cfe56b08";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-August-4309890fd6df404aa8152d3957fcc9ed";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-August-1942894168b34296a1aa7e6fa079083d";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-August-09ca73f44ad948089d02ce4a266fda90";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-August-6c00024f29594b5083818ad5d1a2b867";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-August-acb2d7ac17ab403d8de0be2cf4ebf8a1";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-August-b1246cb371d844c5a2da35fa2c07f04f";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-August-86aab44c15ca4f0d996a0f1910698a6b";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-August-850cb0c2a235429bbac15f480b6688d5";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-August-9500c289f2324f799b4c7a02bb84802d";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-August-52954d0ffcec43f3bd3f6c21812405eb";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-August-0ca05f19699149a4af999298ac035913";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-August-66487ab868824c588b9deefacebc87d3";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-August-44817eb699154eb68bdd2d62bab741cd";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-August-1d0eefe6ae3b4a8c8b7934a396a49c3d";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-August-5538c4ff936d4c9d9242c6a208d32d5f";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-August-bf099939cfb749568c1d389fa7f7810b";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_September(Month *MonthArray){
    string day_link;
    int M = 8;
    day_link = "1st-September-43efc45dd2cc484f9d7ad2f809104c24";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-September-5cafd28d976749278acc97dd4e8fc5c4";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-September-c3971dde358041a3bb2aa9968c7c10af";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-September-8837cca7075c40adb83d36fa7c8764f9";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-September-90327e02b0734280aad239a9a0c22a68";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-September-7644565cff2b4ecaafcf78474b5d5382";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-September-2a9938fb4c60472cbd1bb2f4ac611c95";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-September-d53982295b5d4e0a9f4b830349e4964e";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-September-f627a5b248d54b118944607cda53625d";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-September-aa12e9f0ff7f49ac9e2639f44d631c33";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-September-67a5ed42041c4ece8412bfcc67f4edd5";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-September-15ee2a636878439e8724d6814ab087d6";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-September-32c6ed76e9bc4873a2608ecc39fd9798";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-September-784409e938d843b0a6f5c2f3d8f98f58";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-September-cee167208a634e298db851b4491a34d3";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-September-6bfc496bb4844e2aa2e1d3a51efe70e5";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-September-3e357d9509314834b43ddc12bfef67dd";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-September-968c8e7a9a79403e82c7b2c53a44b7fb";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-September-e9c6530a61b74f31ad92d57612e0eb0b";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-September-b5c7fb9906c1468eac826429ed38b848";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-September-079d7dd8bdd54ad3a63c2441dc0aead2";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-September-fcdd82aeb1044a9f9db8111c96eb7b26";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-September-3775586f291a4f68afce312ba52bc18d";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-September-53836f357c1243499a2c79c30a881fe0";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-September-20c6d8ffed23473cb63fa6ea349ed398";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-September-a89982196ee742df97db5326befcaa35";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-September-d4c086a8da6443cc82b630eae8bdcb24";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-September-d9a9b201aad24fcaa0e6a2e8c2173e9c";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-September-f60abff8ead345149cf4116dfd41994d";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-September-8e34570c87d64e858913773e896c1386";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
}

void Setup_October(Month *MonthArray){
    string day_link;
    int M = 9;
    day_link = "1st-October-7e625f02d7a34baeb6943b61c9f47370";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-October-3ecf88e309c4446ebfbf291947ebb677";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-October-3942360f3cd142da81b9b8689db33523";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-October-1a518f4f7baa4b29988e89243217fff4";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-October-7326756dba63410696eb4249a8214fd0";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-October-be9feacbfac1461bb8b7876fa01736e8";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-October-8ffec7c4957e4f1c80c07be3454b560a";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-October-755bbb5d7c754d4faf33eef244c141fb";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-October-2977dcff5586467faa21acddba044b8b";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-October-148c7ffecada4ebb9e770efb76fd418c";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-October-bf01b9f902f64879934a47701babfe53";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-October-9b4701423c214a729d323cf7be7272a7";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-October-a98a8718b3674924b78adbe8aa63e262";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-October-05f239d55a03474da821ada6ed9b36d6";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-October-eabea62f02ad4f85a87de8247f00fd92";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-October-6d828b2117594877867d144e6724a80b";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-October-f9329307b0ff4cd18e695de6fd69b075";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-October-5e97ecd860894472a9741a7ec48b938d";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-October-9ff9b48383e046069fb4c542b6fce82c";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-October-af3a2b50636b4066b850bc03cd869039";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-October-e6921fc1b8e342b19fc014a68c7d24c5";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-October-8e63c0c3c50c4157b41e24d551be0c04";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-October-a4aee2ba38914ad8bca17d7421202044";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-October-8b29fad9526441479cb5f033045b6bab";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-October-2314184421104466866791cd98ec8221";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-October-3fa9896bf3af4c12bc2c35cfff5eba05";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-October-dc1d25ebb3864207b1517d4b4e4c2064";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-October-0b0aa538347142b58156a97dd38ffc23";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-October-35ecdaed8dc44c20b6459517287ae581";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-October-e08e9e7c2dd0425aaffbb24eba9a1f35";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-October-19779defd6e745b7bf0e13f489de7efb";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_November(Month *MonthArray){
    string day_link;
    int M = 10;
    day_link = "1st-November-82627d61b4434108b5068f9019256c5b";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-November-fae13053407a4079b7c5e1ba3d8286d7";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-November-411fec0f02ac49ff991c968b08acad0a";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-November-9019777e82bc4f2c9566890fe3f6935f";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-November-9282d807467744eaa64b45c134454cd1";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-November-18575514352b4b5e9ebca11924a96945";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-November-9280ca712a0b494184ac9e9bc610c1bc";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-November-fcff2de4c2c3408d876b0768c9bdcc4e";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-November-63b8d0881ef148ea8a4a874d47c2eff0";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-November-95a61f5b42684cfb95b34b8bf499318b";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-November-c25f9559d9694b2eb3a8cc8dccab2641";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-November-e17d6215fd554364b59a31c2e1cd55ec";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-November-c3469b07880a440d9dc506f253e9548c";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-November-b6059eb78dae4bdbb95414db3f125164";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-November-3b62a86c1c804ec2af84153fdf1b2b89";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-November-2c388f68a69f41a6a32931d05284cbfb";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-November-01cc9abe48a049c78a09c9fb656fa4e3";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-November-ddcd29d1b8bd414f95f1c8e56323e402";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-November-2b6e729ec5ad46438d6bfb0bd40ac1a8";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-November-b05be9e2503c4a858b9a24a179d624fc";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-November-4685d76394984528aa6f858ce3635c20";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-November-b97af2af52b646b9a019f89be139dc99";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-November-cd268642c571477c9e59ff7a0039e611";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-November-8cb577a56edc434a8069df36fc160738";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-November-d948da764c214c1caae529e9647dc8ae";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-November-b9a4f4ce9fa74865b70d1f3f6cde5ce3";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-November-eb80639c62064b778d3c8ac40a4323d7";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-November-2dda74448a7841ed9c7579a7ebe05330";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-November-022378a8b212453587074ffec8452afa";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-November-a73132f9f0b34335815b7714700a8a83";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
}

void Setup_December(Month *MonthArray){
    
    string day_link;
    int M = 11;
    day_link = "1st-December-9794af43fb254bdcabeb0091459fff98";
    MonthArray[M].DayArray[0] = Day( 0 , day_link);
    
    //Next Day
    day_link = "2nd-December-e3259b7b7bf542e28b9b7bdfcf9ed990";
    MonthArray[M].DayArray[1] = Day( 1, day_link);

    //Next Day
    day_link = "3rd-December-159eb3b7b5ce40c9a76b59e097206052";
    MonthArray[M].DayArray[2] = Day( 2, day_link );

    //Next Day
    day_link = "4th-December-64475a8530984080976778120077ffd1";
    MonthArray[M].DayArray[3] = Day( 3, day_link );

    //Next Day
    day_link = "5th-December-8ab65f815e6445e287a5eadb3eb9a680";
    MonthArray[M].DayArray[4] = Day( 4, day_link );

    //Next Day
    day_link = "6th-December-4c5e5e301ada4d2a961c6e61b1349116";
    MonthArray[M].DayArray[5] = Day( 5, day_link );

    //Next Day
    day_link = "7th-December-83d3bd7bd62e401086dc1de0380a3072";
    MonthArray[M].DayArray[6] = Day( 6, day_link );

    //Next Day
    day_link = "8th-December-dbd651c0fad64c66977b52799cdf03cc";
    MonthArray[M].DayArray[7] = Day( 7, day_link );

    //Next Day
    day_link = "9th-December-2c945f1d6d734bcaa26439d025bab09f";
    MonthArray[M].DayArray[8] = Day( 8, day_link );

    //Next Day
    day_link = "10th-December-d788ce6257824fc8a312a721b7f06054";
    MonthArray[M].DayArray[9] = Day( 9, day_link );

    //Next Day
    day_link = "11th-December-4bca22dfaeb346e195b6cdcaa850da71";
    MonthArray[M].DayArray[10] = Day( 10, day_link );

    //Next Day
    day_link = "12th-December-4b9d6a39e3174a2aa2eace059d88dc4d";
    MonthArray[M].DayArray[11] = Day( 11, day_link );

    //Next Day
    day_link = "13th-December-ab5dcdef539e4d1aa96ff068d2a96981";
    MonthArray[M].DayArray[12] = Day( 12, day_link );

    //Next Day
    day_link = "14th-December-3fe73801b7aa45bfa44b97badc094bf2";
    MonthArray[M].DayArray[13] = Day( 13, day_link );

    //Next Day
    day_link = "15th-December-344b6ae2701840f4a97c101527caa23d";
    MonthArray[M].DayArray[14] = Day( 14, day_link );

    //Next Day
    day_link = "16th-December-94a3675987364d31be19eee1f850398b";
    MonthArray[M].DayArray[15] = Day( 15, day_link );

    //Next Day
    day_link = "17th-December-798fdfecf16643a599b897e62b74913a";
    MonthArray[M].DayArray[16] = Day( 16, day_link );

    //Next Day
    day_link = "18th-December-5669dde7adf34f319c893212360190b1";
    MonthArray[M].DayArray[17] = Day( 17, day_link );

    //Next Day
    day_link = "19th-December-6039b2dc95af438a9f7b722cfe231220";
    MonthArray[M].DayArray[18] = Day( 18, day_link );

    //Next Day
    day_link = "20th-December-d768aeaf1cb443baba6bd55f89b607f1";
    MonthArray[M].DayArray[19] = Day( 19, day_link );

    //Next Day
    day_link = "21st-December-f483e0e77b5d4d22ac7a578aaa7b0b2d";
    MonthArray[M].DayArray[20] = Day( 20, day_link );

    //Next Day
    day_link = "22nd-December-a6c05402559244728279ab0ab16e1cb9";
    MonthArray[M].DayArray[21] = Day( 21, day_link );

    //Next Day
    day_link = "23rd-December-cfd8a4a82c564b749141811ee5b02d66";
    MonthArray[M].DayArray[22] = Day( 22, day_link );

    //Next Day
    day_link = "24th-December-289251419ceb4091bc94ef59eafccd44";
    MonthArray[M].DayArray[23] = Day( 23, day_link );

    //Next Day
    day_link = "25th-December-47b95c0648e44dd6b0533b122b04ffdc";
    MonthArray[M].DayArray[24] = Day( 24, day_link );

    //Next Day
    day_link = "26th-December-c1eac99e1cd449d589776887296fe18e";
    MonthArray[M].DayArray[25] = Day( 25, day_link );

    //Next Day
    day_link = "27th-December-d5f87f8731d2459c9a80fc8fc0e10e90";
    MonthArray[M].DayArray[26] = Day( 26, day_link );

    //Next Day
    day_link = "28th-December-2828d5d7090743bd8666ac3dc16d9bad";
    MonthArray[M].DayArray[27] = Day( 27, day_link );

    //Next Day
    day_link = "29th-December-3c36c5060a2f471988600f1b4d7dd681";
    MonthArray[M].DayArray[28] = Day( 28, day_link );

    //Next Day
    day_link = "30th-December-0d5a2d98cf2c45c480433328a3078c85";
    MonthArray[M].DayArray[29] = Day( 29, day_link );
    
    //Next Day
    day_link = "31st-December-44f99a3c4b5b4da9b1f98a09d0f36518";
    MonthArray[M].DayArray[30] = Day( 30, day_link );
}

void Setup_Month (Month *MonthArray){

    MonthArray[0] = Month(31 , "January");
            Setup_January(MonthArray);

    MonthArray[1] = Month(29 , "February");
            Setup_February(MonthArray);

    MonthArray[2] = Month(31 , "March");
            Setup_March(MonthArray);

    MonthArray[3] = Month(30 , "April");
            Setup_April(MonthArray);
        
    MonthArray[4] = Month(31 , "May");
            Setup_May(MonthArray);
    
    MonthArray[5] = Month(30 , "June");
            Setup_June(MonthArray);
        
    MonthArray[6] = Month(31 , "July");
            Setup_July(MonthArray);
        
    MonthArray[7] = Month(31 , "August");
            Setup_August(MonthArray);
    
    MonthArray[8] = Month(30 , "September");
            Setup_September(MonthArray);
    
    MonthArray[9] = Month(31 , "October");
            Setup_October(MonthArray);
    
    MonthArray[10] = Month(30 , "November");
            Setup_November(MonthArray);
    
    MonthArray[11] = Month(31 , "December");
            Setup_December(MonthArray);

}

int main(){

    Month MonthArray[12];

    Setup_Month (MonthArray); //Add all the respective month objects to the array[12]
    cout<<endl<<endl<<"                              WELCOME TO OUR PROJECT:: MAST KALANDAR :)                              "<<endl; 
    cout<<endl<<"Read or Write "<<endl;
    cout<<"1. Write Today's diary"<<endl; //You can not write or change past diaries
    cout<<"2. Read Past Diary"<<endl;
    // cout<<"2. See Past diaries"<<endl; //If want to read diary ask want diary 
    // cout<<"3. See Past Photos"<<endl;  //Then cout last editted //Then ask if want to be redirected.
    cout<<"3. Add Event "<<endl; //Just pushback in the days list. No need to check date;
    cout<<"4. Watch Google Photos Timeline"<<endl; //or Photos then ask for password for photos;
    cout<<"5. See last editted details"<<endl; //enter password
    int userInput;
    cin>>userInput;
    string redirect_link;
    string userDate,userValue;

        time_t timeNow = time(0);
        tm *dateTimeNow = localtime(&timeNow);
        int currDay = dateTimeNow->tm_mday;
        int currMonth = dateTimeNow->tm_mon;
    switch (userInput)
    {
    case 1:
        
        redirect_link = MonthArray[currMonth].DayArray[currDay-1].Get_Day_link();
        break;

    case 2:

        cout<<"Enter A Date"<<endl;
        cin>>userDate;
        cout<<"You Can't edit this date's diary, do you want to read it (Yes/No)?"<<endl;
        cin>>userValue;
        if(userValue=="Yes"){
            redirect_link = MonthArray[trimmedMonth(userDate) - 1].DayArray[trimmedDay(userDate)  - 1].Get_Day_link(userDate);
            cout<<redirect_link;
        }
        break;
    case 3:

        cout<<"Enter A Date"<<endl;
        cin>>userDate;
        cout<<"Enter the Event"<<endl;
        cin>>userValue;
        MonthArray[trimmedMonth(userDate) - 1].DayArray[trimmedDay(userDate)  - 1].Set_events(userValue);
        break;
    
    case 4:
        cout<<"Do you want to search: (1)A Date (2)A Keyword"<<endl;
        cin>>userInput;
        if(userInput==1){
            cout<<"Enter a date you want to search on the timeline"<<endl;
            cin>>userValue;
            int x = trimmedMonth(userValue);
            int y = trimmedDay(userValue);
            redirect_link =  MonthArray[x - 1].DayArray[y - 1].photos_datelink(y , x);
        }else{
            cout<<"Enter an Event you want to search on the timeline"<<endl;
            cin>>userValue;
            int x = trimmedMonth(userValue);
            int y = trimmedDay(userValue);
            redirect_link =  MonthArray[x - 1].DayArray[y - 1].photos_search_link(userValue);
        }
    default:
        break;
    }
    // string date; //in DDMMYYYY format
    // cin>>date;

        // cout<<""<<endl;
        cout<<"Thanks for visiting, Your Secrets are Safe with us."<<endl;
        cout<<endl<<"* *************************************************************************************************************************************"<<endl;
        system(redirect_link.c_str());
        

}
