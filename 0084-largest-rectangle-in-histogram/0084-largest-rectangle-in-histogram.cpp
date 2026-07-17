class Solution {
public:

vector<int> previousSmaller(vector <int> & heights){
    int n = heights.size();

    vector<int>pse(n);
    stack<int> st;

    for(int i=0; i<n ; i++){
        while(!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

        if(st.empty())
        pse[i]= -1;

        else
        pse[i] = st.top();

        st.push(i);
    }
    return pse;
}


vector<int> nextSmaller(vector <int> & heights){
    int n =heights.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n-1; i >=0 ; i--){
        while(!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

        if(st.empty())
        nse[i]= n;
        else
        nse[i] = st.top();

        st.push(i);


    }
return nse;    
}


    int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();

        vector<int>pse = previousSmaller(heights);
        vector<int>nse = nextSmaller(heights);

        int ans = 0;

        for(int i=0; i<n; i++){

            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            ans = max(ans, area);
        }
        return ans;
    }
};