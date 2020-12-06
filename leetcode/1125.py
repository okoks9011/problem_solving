class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        n = len(req_skills)
        skill_dic = {skill: i for i, skill in enumerate(req_skills)}
        dp = {0: []}
        for pi, skills in enumerate(people):
            cur_skill = 0
            for skill in skills:
                cur_skill |= 1 << skill_dic[skill]

            for saved_skill, need in list(dp.items()):
                with_skill = cur_skill | saved_skill
                if with_skill == saved_skill:
                    continue
                if with_skill not in dp or len(dp[with_skill]) > len(need) + 1:
                    dp[with_skill] = need + [pi]
        return dp[(1 << n) - 1]
