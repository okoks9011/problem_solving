"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        employee_dic = {employee.id: employee for employee in employees}
        def cal_importance(cur_id):
            cur_employee = employee_dic[cur_id]
            return cur_employee.importance + sum(cal_importance(sub) for sub in cur_employee.subordinates)

        return cal_importance(id)
