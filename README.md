list (XOR Linked List)
======
class template <br>
std::list
<hr>

<pre>C++ Linked List template that uses XOR operations to reduce memory usage.</pre>

Constructors
------
list&lt;type&gt; name;
> create an empty Linked List

Fields
------
<table>
  <tr> <th>accessor</th> <th>type</th> <th>name</th> <th>description</th> </tr>
  
  <tr> <td>private</td> <td>long long int</td> <td>_length</td> <td>length of LinkedList</td> </tr>

  <tr> <td>private</td> <td>bool</td> <td>_isLength</td> <td>has ever update length of LinkedList</td> </tr>

  <tr> <td>private</td> <td>list::node*</td> <td>_firstNode</td> <td>firstNode of LinkedList</td> </tr>

  <tr> <td>private</td> <td>list::node*</td> <td>_lastNode</td> <td>lastNode of LinkedList</td> </tr>
<table>

Methods
------
<table>
  <tr> <th>accessor</th> <th>return type</th> <th>method</th> <th>description</th> </tr>
  
  <tr> <td>public</td> <td>void</td> <td>push_back(T data)</td> <td>push the newNode back</td> </tr>
  
  <tr> <td>public</td> <td>void</td> <td>push_front(T data)</td> <td>push the newNode front</td> </tr>
  
  <tr> <td>public</td> <td>void</td> <td>pop_back()</td> <td>pop node from back</td> </tr>
  
  <tr> <td>public</td> <td>void</td> <td>pop_front()</td> <td>pop node from front</td> </tr>
  
  <tr> <td>public</td> <td>long long int</td> <td>length()</td> <td>get length</td> </tr>

  <tr> <td>public</td> <td>void</td> <td>printList()</td> <td>print all data in LinkedList</td> </tr>
  
  <tr> <td>private</td> <td>list::node*</td> <td>getNext(list::node* prev, list::node* now)</td> <td>get next node</td> </tr>
  
  <tr> <td>private</td> <td>list::node*</td> <td>getPrev(list::node* now, list::node* next)</td> <td>get previous node</td> </tr>
  
  <tr> <td>private</td> <td>list::node*</td> <td>count()</td> <td>update length</td> </tr>
</table>
