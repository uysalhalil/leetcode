#include <stack>
#include <vector>

class Solution {
   private:
    std::vector<bool> visited;  // visited rooms

    void dfs(const std::vector<std::vector<int>>& rooms, int currentRoom) {
        if (visited[currentRoom]) return;
        visited[currentRoom] = true;
        for (auto neighbor : rooms[currentRoom]) {
            dfs(rooms, neighbor);
        }
    }

   public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        visited.resize(rooms.size(), false);
        dfs(rooms, 0);
        for (auto v : visited) {
            if (!v) return false;
        }
        return true;
    }
};

// class Solution {
//    private:
//     std::vector<bool> visited;  // visited rooms
//    public:
//     bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
//         visited.resize(rooms.size(), false);
//         visited[0] = true;
//         std::stack<std::vector<int>> nextRooms;
//         nextRooms.push(rooms[0]);
//         while (!nextRooms.empty()) {
//             auto neighbors = nextRooms.top();
//             nextRooms.pop();
//             for (auto &neighbor : neighbors) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     nextRooms.push(rooms[neighbor]);
//                 }
//             }
//         }
//         for (auto &&v : visited) {
//             if (!v) return false;
//         }
//         return true;
//     }
// };