class Solution {
public:
    vector<vector<int>> adjacencyList;  // Adjacency list to represent the course prerequisites
    vector<int> inDegrees;  // In-degree of each course (number of prerequisites)

    // Kahn's Algorithm
    int calculateMinimumTime(int n, vector<int>& time) {
        vector<int> waitTime(n + 1) ; // keep track of wait time for each course
        queue<pair<int, int>> q;  // queue for topological sort
        int maxWaitTime = 0;  // Maximum wait time for completing all courses

        // Initialize the queue with courses that have no prerequisites
        for (int i = 1; i <= n; i++) {
            if (inDegrees[i] == 0) {
                q.push({time[i - 1], i});
                waitTime[i] = time[i - 1] ;
            }
        }

        // Perform topological sort
        while (!q.empty()) {
            auto currentNode = q.front();
            q.pop();
            int currentCourseTime = currentNode.first;
            maxWaitTime = max(maxWaitTime, currentCourseTime);
            int currentCourse = currentNode.second;

            // Process each course that depends on the current course
            for (auto childCourse : adjacencyList[currentCourse]) {
                inDegrees[childCourse]--;
                waitTime[childCourse] = max(time[childCourse - 1] + waitTime[currentCourse], waitTime[childCourse]);

                // If all prerequisites are completed, update the wait time and add to the priority queue
                if (inDegrees[childCourse] == 0) 
                    q.push({waitTime[childCourse], childCourse});
            }
        }

        return maxWaitTime;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adjacencyList.resize(n + 1);
        inDegrees.resize(n + 1);

        // Build the adjacency list and calculate in-degrees for each course
        for (int i = 0; i < relations.size(); i++) {
            auto prerequisitePair = relations[i];
            adjacencyList[prerequisitePair[0]].push_back(prerequisitePair[1]);
            inDegrees[prerequisitePair[1]]++;
        }

        return calculateMinimumTime(n, time);
    }
};