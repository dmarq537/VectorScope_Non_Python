import { useEffect, useState } from 'react';

export default function App() {
  const [value, setValue] = useState(0.5);
  const [ws, setWs] = useState(null);

  useEffect(() => {
    const socket = new WebSocket('ws://localhost:9002');
    socket.onopen = () => console.log('WebSocket connected');
    socket.onmessage = (ev) => console.log('Message from server:', ev.data);
    setWs(socket);
    return () => socket.close();
  }, []);

  const handleChange = (e) => {
    const v = e.target.value;
    setValue(v);
    if (ws && ws.readyState === WebSocket.OPEN) {
      ws.send(JSON.stringify({ amplitude: v }));
    }
  };

  return (
    <div>
      <h1>Vectorscope Controls</h1>
      <input type="range" min="0" max="1" step="0.01" value={value} onChange={handleChange} />
    </div>
  );
}
