#include <Node.hpp>

Node::Node()
{
    setContent(0);
    setPrevious(0);
    setNext(0);
}

Node::~Node()
{

}

int Node::getContent()
{
    return content;
}

int Node::getPrevious()
{
    return previous;
}

int Node::getNext()
{
    return next;
}

void Node::setContent(int newContent)
{
    content = newContent;
}

void Node::setPrevious(int newPrevious)
{
    previous = newPrevious;
}

void Node::setNext(int newNext)
{
    next = newNext;
}