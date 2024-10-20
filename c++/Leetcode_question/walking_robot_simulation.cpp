Intuition
Loop through all the commands and handle the cases accordingly.
For every step we need to check whether the step is in the obstacle or not.
For every command we need to update our final distance to be maximum.
Return the final maximum answer.
Approach
Store all the obstacles in a map to retrieve data in constant time O(1).
Loop through all the commands, according to the command update the direction (dir) : 0 --> North, 1 --> East, 2 --> South, 3 --> West
If the command[i] is -2, We need to in anti - clockwise, so subtract 1 from the dir, else if command[i] is -1, we need to go in clockwise direction so add 1 to dir.
While going each step at a time, we check whether the step is in the obstacle map or not. If it is present in the obstacle map we break the loop and go to next command, else we update the co-ordinates according to the command.
At the end of every command, we update our maximum distance to that point wrt origin.
Return the final maximum answer.
Complexity
Time complexity:
O(m+k∗n)
where k = [1,9]
m = number of pairs in obstacles array(To store in map)
n = length of commands array

Space complexity:
O(m)(To store obstacles)

Code
class Solution {
public:

    bool isValid(int x, int y, unordered_map<string,int> &map){
        
        string ob = to_string(x) + "," + to_string(y);
        
        if(map.find(ob) != map.end()) return false;

        return true;
    }

    pair<int,int> getCords(pair<int,int> co, int k,unordered_map<string,int> &map, int dir){

        int x = co.first, y = co.second;
        for(int i = 1 ; i <= k ; i++){

            if(dir == 0){
                if(isValid(x,y+1,map)) y += 1;
                else break;
            }else if(dir == 1){
                if(isValid(x+1,y,map)) x += 1;
                else break;
            }else if(dir == 2){
                if(isValid(x,y-1,map)) y -= 1;
                else break;
            }else if(dir == 3){
                if(isValid(x-1,y,map)) x -= 1;
                else break;
            }

        }
        
        return {x,y};

    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int dir = 0, ans = 0;
        unordered_map<string,int> map;

        for(auto it : obstacles){
            string s = to_string(it[0]) + "," + to_string(it[1]);
            map[s] = 1;
        }

        pair<int,int> co = {0,0};

        for(int i = 0 ; i < commands.size() ; i++){

            if(commands[i] == -2){
                dir -= 1;
                if(dir < 0) dir += 4;
            }else if(commands[i] == -1){
                dir = (dir + 1) % 4;
            }else{
                pair<int,int> cords = getCords(co,commands[i],map,dir);
                co = cords;
                ans = max(ans,co.first * co.first + co.second * co.second);
            }
        }

        return ans;
        
    }
};
