class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.empty_text_editor(s) == self.empty_text_editor(t)
    
    def empty_text_editor(self, bef):
        aft = ""
        for c in bef:
            if c == "#":
                aft = aft[:-1]
            else:
                aft = aft + c
        return aft