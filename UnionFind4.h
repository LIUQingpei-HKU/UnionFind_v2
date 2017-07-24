//
// Created by LIU Qingpei on 23/7/2017.
//

#ifndef UNIONFIND_QUICKUNION_UNIONFIND4_H
#define UNIONFIND_QUICKUNION_UNIONFIND4_H
#include <cassert>

using namespace std;


namespace UF4{
    class UnionFind{
    private:
        int* parent;
        int* rank;
        int count;
    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for(int i=0;i<count;i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind(){
            delete[] parent;
            delete rank;
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

            if(rank[pRoot]<rank[qRoot]) {
                parent[pRoot] = qRoot;

            }else if(rank[qRoot]<rank[pRoot]){
                parent[qRoot] = pRoot;
            }else{//rank[qRoot]==rank[pRoot]
                parent[pRoot] = qRoot;
                rank[qRoot]+=1;
            }


        }
    };

}
#endif //UNIONFIND_QUICKUNION_UNIONFIND4_H
