#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;



int fifo(int capacity, vector<int> requests)
{
    unordered_set<int> cache;
    unordered_map<int, int> times;

    int misses = 0;
    int request;

    for(int i = 0; i < requests.size(); i++)
    {

        request = requests[i];

        if (cache.count(request) > 0)
        {
            //Hit
            continue;
        }

        else
        {
            //Miss
            misses++;

            //Insert if not at capacity
            if(cache.size() < capacity)
            {
                cache.insert(request);
                times[request] = i;
            }

            //Replace if at capacity
            else
            {
                int min_item = times.begin()->first;
                int min_time = times.begin()->second;
                
                for(auto it = times.begin(); it != times.end(); ++it)
                {
                    if(it->second < min_time)
                    {
                        min_item = it->first;
                        min_time = it->second;
                    }
                }


                times.erase(min_item);
                cache.erase(min_item);
                cache.insert(request);
                times[request] = i;
            }
        }
    }



    return misses;
}




int lru(int capacity, vector<int> requests)
{

    unordered_set<int> cache;
    unordered_map<int, int> times;

    int misses = 0;
    int request;

    for(int i = 0; i < requests.size(); i++)
    {
        request = requests[i];

        if (cache.count(request) > 0)
        {
            //Hit, update time if used
            times[request] = i;
        }

        else
        {
            //Miss
            misses++;

            //Insert if not at capacity
            if(cache.size() < capacity)
            {
                cache.insert(request);
                times[request] = i;
            }

            //Replace if at capacity
            else
            {
                int min_item = times.begin()->first;
                int min_time = times.begin()->second;
                
                for(auto it = times.begin(); it != times.end(); ++it)
                {
                    if(it->second < min_time)
                    {
                        min_item = it->first;
                        min_time = it->second;
                    }
                }


                times.erase(min_item);
                cache.erase(min_item);
                cache.insert(request);
                times[request] = i;
            }
        }
    }

    return misses;
}


int optff(int capacity, vector<int> requests)
{
    unordered_set<int> cache;
    int misses = 0;

    for(int i = 0; i < requests.size(); i++)
    {
        int request = requests[i];

        //Hit
        if (cache.count(request) > 0)
        {
            continue;
        }

        //Miss
        misses++;

        //Cache not full
        if(cache.size() < capacity)
        {
            cache.insert(request);
        }

        //Cache full
        else
        {
            int farthest = i + 1;
            int last = -1;

            for (int page : cache)
            {
                int next_occurrence = i + 1;
                
                while (next_occurrence < requests.size())
                {
                    if (requests[next_occurrence] == page)
                        break;
                    next_occurrence++;
                }

                if (next_occurrence == requests.size())
                {
                    last = page;
                    break;
                }

                if (next_occurrence > farthest)
                {
                    farthest = next_occurrence;
                    last = page;
                }
            }

            if (last == -1)
            {
                last = *cache.begin();
            } 

            cache.erase(last);
            cache.insert(request);
        }
    }
    
    return misses;
}