from collections import deque


class RecentCounter:

    def __init__(self):
        self.timeWindow = 3000
        self.pingQueue = deque()

    def ping(self, t: int) -> int:
        self.pingQueue.append(t)
        startingTime = max(t - self.timeWindow, 0)
        while self.pingQueue[0] < startingTime:
            self.pingQueue.popleft()
        return len(self.pingQueue)