class Solution:
    def textEdit(self, sent):
        stack = []
        for s in sent:
            if s == "#" and len(stack) != 0:
                stack.pop()
            elif s == "#" and len(stack) == 0:
                continue
            else: 
                stack.append(s)
        return stack
            
    def backspaceCompare(self, s: str, t: str) -> bool:
        sStack = self.textEdit(s)
        tStack = self.textEdit(t)
        if sStack == tStack:
            return True
        return False