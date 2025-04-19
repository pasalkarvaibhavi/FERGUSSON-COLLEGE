import React,{Component} from 'react';

class DataFetcher extends Component{

    constructor(props) {
        super(props);
        this.state = {
          data: [], 
          loading: true, 
          error: null, 
        };
      }

      componentDidMount() {
      fetch("https://jsonplaceholder.typicode.com/posts") 
      .then((response) => {
        if (!response.ok) {
          throw new Error("Network response was not ok");
        }
        return response.json();
      })
      .then((data) => this.setState({ data, loading: false }))
      .catch((error) => this.setState({ error, loading: false }));
  }

  render() {
    const { data, loading, error } = this.state;

    if (loading) {
      return <h3>Loading...</h3>;
    }

    if (error) {
      return <h3>Error: {error.message}</h3>;
    }

    return (
      <div>
        <h2>Fetched Data</h2>
        <ul>
          {data.slice(0, 10).map((item) => (
            <li key={item.id}>
              <strong>{item.title}</strong>
              <p>{item.body}</p>
            </li>
          ))}
        </ul>
      </div>
    );
  }
}
export default DataFetcher;   