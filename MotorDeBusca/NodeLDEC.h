#ifndef NodeLDEC_H
#define NodeLDEC_H
#include <QString>
namespace ED1 {

template < class Type>
class NodeLDEC
{
private:
    Type data;
    NodeLDEC *post_link;
    NodeLDEC *pre_link;
public:
    NodeLDEC();
    NodeLDEC(Type element, NodeLDEC * const postlink, NodeLDEC * const prelink);
    NodeLDEC(Type element):data(element),post_link(0),pre_link(0){}
    Type getData() const { return data;}
    NodeLDEC* getPostLink() const{ return post_link;}
    NodeLDEC* getPreLink() const {return pre_link;}
    void setData(Type element){  data=element;}
    void setPreLink(NodeLDEC * const prelink){ pre_link = prelink; }
    void setPostLink(NodeLDEC * const postlink){ post_link = postlink; }
};//fim declaração da classe

template <class Type>
NodeLDEC<Type>::NodeLDEC():
    data(0),
    post_link(0),
    pre_link(0)
{

}
template <class Type>
NodeLDEC<Type>::NodeLDEC(Type element, NodeLDEC * const postlink, NodeLDEC * const prelink):
    data(element),
    post_link(postlink),
    pre_link(prelink)
{
}
}//fim namespace
#endif // NodeLDECS_H
