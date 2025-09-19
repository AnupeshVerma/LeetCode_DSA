class Spreadsheet:

    def __init__(self, rows: int):
        self.rows = rows
        self.sheet = {}

    def setCell(self, cell: str, value: int) -> None:
        self.sheet[cell] = value

    def resetCell(self, cell: str) -> None:
        self.sheet[cell] = 0
        

    def getValue(self, formula: str) -> int:
        plus_position = formula.find('+')
        s1 = formula[1:plus_position]
        s2 = formula[plus_position+1:]

        left  = self.sheet.get(s1, 0) if s1[0].isupper() else int(s1)
        right = self.sheet.get(s2, 0) if s2[0].isupper() else int(s2)

        return left + right

# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)