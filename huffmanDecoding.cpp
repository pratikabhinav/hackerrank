void decode_huff(node * root, string s) {
      node *p = root;
    for(int i = 0 ; s[i]; i++) {

        if(s[i] == '0') {
            p = p->left;
        }
        else {
            p = p->right;
        }

        if(p->left == nullptr && p->right == nullptr) {
            printf("%c", p->data);
            p = root;
        }
    }
}