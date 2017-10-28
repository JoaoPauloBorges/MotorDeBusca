#ifndef NODESTACK_H
#define NODESTACK_H

namespace ED1 {

template <class tipo>
class NodeStack
{
private:
    tipo data;
    NodeStack *pre_link;
    NodeStack *post_link;


public:
    NodeStack();
    NodeStack(tipo data, NodeStack * const pre_link, NodeStack * const post_link );
    NodeStack(tipo data):data(data),pre_link(NULL),post_link(NULL){}
    tipo getData() const{return data;}
    void setData(const tipo data){this->data=data;}
    NodeStack *getPreLink() const{return pre_link;}
    NodeStack *getPostLink() const{return post_link;}
    void setPreLink(NodeStack *const pre_link){this->pre_link=pre_link;}
    void setPostLink(NodeStack *const post_link){this->post_link=post_link;}
};
template <class tipo>
NodeStack<tipo>::NodeStack():
    pre_link(NULL),
    post_link(NULL)
{

}
template <class tipo>
NodeStack<tipo>::NodeStack(tipo data, NodeStack * const pre_link, NodeStack * const post_link):
    data(data),
    pre_link(pre_link),
    post_link(post_link)

{

}


}//fim namespace

#endif // NODESTACK_H
