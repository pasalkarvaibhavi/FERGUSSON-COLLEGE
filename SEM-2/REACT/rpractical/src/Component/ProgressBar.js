import React from 'react';
import './ProgressBar.css';

const ProgressBar = ({ progress, color, height, showLabel }) => {
  return (
    <div className="progress-bar-container" style={{ height: height }}>
      <div
        className="progress-bar-filler"
        style={{
          width: `${progress}%`,
          background: color, 
        }}
      >
        {showLabel && (
          <span className="progress-bar-label">{`${progress}%`}</span>
        )}
      </div>
    </div>
  );
};

ProgressBar.defaultProps = {
  progress: 0,
  color: 'linear-gradient(90deg, #76c7c0, #4caf50)', 
  height: '25px',
  showLabel: true, 
};

export default ProgressBar;