//
// Created by liuyubobobo on 9/2/16.
//

#ifndef INC_03_QUICK_UNION_UNIONFIND2_H
#define INC_03_QUICK_UNION_UNIONFIND2_H

#include <cassert>

using namespace std;

// 我们的第二版Union-Find
namespace UF2{
    class UnionFind{
    private:
        int* parent;
        int count;
    public:
        UnionFind(int count){
            parent = new int[count];
            this->count = count;
            for(int i=0;i<count;i++)
                parent[i] = i;
        }
        ~UnionFind(){
            delete[] parent;
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
            parent[pRoot] = qRoot;

        }
    };

}

#endif //INC_03_QUICK_UNION_UNIONFIND2_H
