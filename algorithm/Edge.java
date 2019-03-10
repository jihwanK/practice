public class Edge {
    private int lower_bound;
    private int capacity;
    private int flow;
    private char type;

    public Edge(int lower_bound, int capacity) {
        this.lower_bound = lower_bound;
        this.capacity = capacity;
    }

    public Edge(int lower_bound, int capacity, int flow) {
        this.lower_bound = lower_bound;
        this.capacity = capacity;
        this.flow = flow;
    }

    public void setType(char type) {
        this.type = type;
    }

    public char getType() {
        return this.type;
    }

    public void setFlow(int flow) {
        this.flow = flow;
    }

    public int getFlow() {
        return this.flow;
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