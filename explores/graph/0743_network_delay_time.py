from collections import deque
import math
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        nan_value = math.nan
        inf_value = math.inf

        graph = {x: [] for x in range(1, n + 1)}
        for edge in times:
            graph[edge[0]].append([edge[1], edge[2]])

        node_visit_times = {x: [inf_value, nan_value] for x in range(1, n + 1)}
        node_visit_times[k] = [0, nan_value]
        q = deque()
        q.append(k)

        while len(q) > 0:
            current_node = q.popleft()
            neighbors = graph[current_node]
            for neighbor in neighbors:
                [prev_time, prev_node] = node_visit_times[neighbor[0]]
                travel_time = neighbor[1] + node_visit_times[current_node][0]
                if travel_time < prev_time:
                    node_visit_times[neighbor[0]] = [travel_time, current_node]
                    q.append(neighbor[0])

        max_time = 0
        for visit_times in node_visit_times.values():
            if visit_times[0] == inf_value:
                return -1
            max_time = max(visit_times[0], max_time)

        return max_time