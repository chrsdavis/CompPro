struct Node
{
  Node* left = nullptr;
  Node* right = nullptr;
  double value;
  double freq = 1;


  Node(double val)
  {
    value = val;
  }

  Node* insert(Node* root, val)
  {
    if(!root)
      return new Node(val);
    if(val > root->val)
      root->right = insert(root->right, val);
    else if(val < root->val)
      root->left = insert(root->left, val);
    else
    {
      root->freq++;
      return root;
    }
  }

  void inOrder(Node* root, std::vector<std::vector<double>>& v)
  {
    if(!root)
      return;
    inOrder(root->left, v);
    std::vector<double> temp = {root->val, root->freq};
    v.push_back(temp);
    inOrder(root->right, v);
  }
};
