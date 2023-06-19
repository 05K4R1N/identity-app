import styled from 'styled-components';

export const Microphone = styled.div`
    background-color: #000;
    min-height: 100vh;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    font-size: calc(10px + 2vmin);
    color: white;

    & button.mic{
        margin: 40px;
        background: red;
    }
    & .mic .icon{
        font-size: 12rem;
        color: #fff;
    }
    & .transcription, & .response{
        margin: 40px;
        color: red;
        font-size: 3rem;
    }
`