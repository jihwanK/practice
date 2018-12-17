public class Edge {
    private int head;
    private int tail;
    private int lower_bound;
    private int capacity;
    private int flow;

    public Edge(int head, int tail, int lower_bound, int capacity) {
        this.head = head;
        this.tail = tail;
        this.lower_bound = lower_bound;
        this.capacity = capacity;
    }

    public Edge(int head, int tail, int lower_bound, int capacity, int flow) {
        this.head = head;
        this.tail = tail;
        this.lower_bound = lower_bound;
        this.capacity = capacity;
        this.flow = flow;
    }

    public void setFlow(int flow) {
        this.flow = flow;
    }

    public int getFlow() {
        return this.flow;
    }

    public void setHead(int head) {
        this.head = head;
    }

    public int getHead() {
        return this.head;
    }

    public void setTail(int tail) {
        this.tail = tail;
    }

    public int getTail() {
        return this.tail;
    }
    
    public void setLowerBound(int lower_bound) {
        this.lower_bound = lower_bound;
    }

    public int getLowerBound() {
        return this.lower_bound;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCapacity() {
        return this.capacity;
    }
}