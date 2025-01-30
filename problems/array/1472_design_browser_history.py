class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.current_index = 0

    def visit(self, url: str) -> None:
        self.current_index += 1
        while len(self.history) > self.current_index:
            self.history.pop()
        self.history.append(url)


    def back(self, steps: int) -> str:
        self.current_index = max(self.current_index - steps, 0)
        return self.history[self.current_index]


    def forward(self, steps: int) -> str:
        self.current_index = min(self.current_index + steps, len(self.history) - 1)
        return self.history[self.current_index]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)