class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        
        path_list = path.split('/')
        p_stack = []
        for p in path_list:
            if p == '..' and p_stack:
                p_stack.pop()
            elif p == '.' or p == '' or p == '..':
                pass
            else:
                p_stack.append(p)
        return '/' + '/'.join(p_stack)
        
