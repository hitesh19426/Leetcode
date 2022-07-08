/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        int rowStart = 0, rowEnd = m-1, colStart = 0, colEnd = n-1;
        while(head && (rowStart <= rowEnd || colStart <= colEnd)){
            if(rowStart <= rowEnd){
                for(int i=colStart; head && i<=colEnd; i++)
                    grid[rowStart][i] = head->val, head = head->next;
            }
            
            if(colStart <= colEnd){
                for(int i=rowStart+1; head && i<rowEnd; i++)
                    grid[i][colEnd] = head->val, head = head->next;
            }
            
            if(rowStart < rowEnd){
                for(int i=colEnd; head && i>=colStart; i--)
                    grid[rowEnd][i] = head->val, head = head->next;
            }
            
            if(colStart < colEnd){
                for(int i=rowEnd-1; head && i>rowStart; i--)
                    grid[i][colStart] = head->val, head = head->next;
            }
            
            rowStart++, rowEnd--, colStart++, colEnd--;
        }
        
        return grid;
    }
};