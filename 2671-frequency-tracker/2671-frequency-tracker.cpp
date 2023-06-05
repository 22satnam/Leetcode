#include<unordered_map>
class FrequencyTracker {
public:
    unordered_map<int,int>map;
    unordered_map<int,int>frequency;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int oldfrequency=map[number];
        int newfrequency=++map[number];
        frequency[oldfrequency]--;
        frequency[newfrequency]++;
    }
    
    void deleteOne(int number) {
        if(map.find(number)!=map.end())
        {
            int oldfrequency=map[number];
            int newfrequency=--map[number];
            frequency[oldfrequency]--;
            if(map[number]==0)
            { map.erase(number);
                return;
            }
            frequency[newfrequency]++;
        }
    }
    
    bool hasFrequency(int freq) {
        
       if(frequency[freq]!=0)
       return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */