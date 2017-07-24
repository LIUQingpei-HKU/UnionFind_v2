//
// Created by LIU Qingpei on 23/7/2017.
//

#ifndef UNIONFIND_QUICKUNION_UNIONFIND3_H
#define UNIONFIND_QUICKUNION_UNIONFIND3_H

#include <cassert>

using namespace std;


namespace UF3{
    class UnionFind{
    private:
        int* parent;
        int* sz;
        int count;
    public:
        UnionFind(int count){
            parent = new int[count];
            sz = new int[count];
            this->count = count;
            for(int i=0;i<count;i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        ~UnionFind(){
            delete[] parent;
            delete sz;
        }

        int findParent(int p){
            assert(p>=0&&p<count);
            while(p!=parent[p])
                p=parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return findParent(p)==findParent(q);
        }

        void unionElements(int p, int q){
            int pRoot = findParent(p);
            int qRoot = findParent(q);

            if(pRoot==qRoot)
                return;

            if(sz[pRoot]<sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }


        }
    };

}
#endif //UNIONFIND_QUICKUNION_UNIONFIND3_H
