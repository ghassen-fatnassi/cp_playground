#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

class Post
{
public:
    virtual void disgplay() = 0;
};

class TextPost : public Post
{
public:
    string owner;
    string content;
    void display() override
    {
        cout << owner << " has shared a TextPost : " << content;
    }
    TextPost(string owner, string content)
    {
        this->owner = owner;
        this->content = content;
    }
    TextPost(TextPost &post)
    {
        owner = post.owner;
        content = post.content;
    }
    ~TextPost()
    {
        cout << "this Post posted by " << owner << " is deleted\n";
    }
};

class ImagePost : public Post
{
public:
    string owner;
    string contentURL;
    void display() override
    {
        cout << owner << " has shared an ImagePost : " << contentURL;
    }
    ImagePost(string owner, string contentURL)
    {
        this->owner = owner;
        this->contentURL = contentURL;
    }
    ImagePost(const ImagePost &post)
    {
        owner = post.owner;
        contentURL = post.contentURL;
    }
    ~ImagePost()
    {
        cout << "this Post posted by " << owner << " is deleted\n";
    }
};

class User
{
private:
    int numberOfSharedPosts;

public:
    string name;
    string password;
    vector<User *> friends;
    // constructors
    User(string name, string password) // parametrized constructor
    {
        this->name = name;
        this->password = password;
    }
    User(const User &user) // copy constructor
    {
        name = user.name;
        password = user.password;
        friends = user.friends;
    }
    // destructor
    ~User()
    {
        cout << name << " is deleted from the platform, all data is lost \n ";
    }

    // sorry got a little excited and implemeted bools as outputs
    // thinking it would be useful to know the state of the user (connected or disconnected)
    // if this was a real project

    // connect
    bool connect(string name, string password)
    {
        if (this->name == name && this->password == password)
        {
            cout << this->name << " Connected , welcome!!\n";
            return 1;
        }
        return 0;
    }
    // disconnect
    bool disconnect()
    {
        cout << this->name << " Connected , welcome!!\n";
        return 0;
    }
    // adding to friend list
    void addFriend(User *Friend)
    {
        friends.push_back(Friend);
        cout << Friend->name << " added to the list of friends of " << name << endl;
    }
    // sharing posts
    void sharePost(Post *post)
    {

        numberOfSharedPosts++;
        cout << "Post shared successfully\n";
        post->display();
    }
    void deletePost()
    {
        numberOfSharedPosts--;
    }
};

class PremiumUser : public User
{
public:
    // constructor
    PremiumUser(string name, string password) : User(name,password)
    {
    }
    // destructor
    ~PremiumUser()
    {
        cout << name << " is deleted from the platform, all data is lost \n ";
        cout << "Goodbye :'(" << endl;
    }
    // viewing profile visitors
    void viewProfileVisitors()
    {
        cout << "Premium feature : Viewing profile visitors ... \n";
    }
};

int main()
{
    FASTIO
    User user1("Alice", "password1");
    User user2("Bob", "password2");
    PremiumUser premiumUser("Charlie", "password3");

    user1.connect("Alice", "password1");
    user2.connect("Bob", "password2");
    premiumUser.connect("Charlie", "password3");

    user1.addFriend(&user2);
    user1.addFriend(&premiumUser);

    TextPost textpost1("Alice", "Hello, World!");
    ImagePost imagepost("Bob", "https:qsdqsdqsdqsdqsdqsd__endofURL.jpg");
    vector<Post *> posts;
    posts.push_back(&textpost1);
    posts.push_back(&textpost1);
    posts.push_back(&imagepost);

    for (auto post : posts)
    {
        post->display();
    }

    user1.sharePost(&textpost1);
    user2.sharePost(&imagepost);


    premiumUser.viewProfileVisitors();
    user1.disconnect();
    user2.disconnect();

    return 0;
}
